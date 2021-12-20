#include <iostream>
#include <math.h>
#include <vector>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "fruchterman_reingold.hpp"
#include "geometry.hpp"

namespace py = pybind11;

void FruchtermanReingold::genInitPos(std::vector<Point> &Positions) const {
  // Initialize the positions of all nodes
  // to form an unit cycle
  const int N = getNumNode();
  const double Theta = 2 * acos(-1.0) / N;
  double t = 0;
  for (int i = 0; i < N; ++i, t += Theta) {
    Positions[i].x = cos(t);
    Positions[i].y = sin(t);
  }
}

void FruchtermanReingold::scalePos(std::vector<Point> &Positions) const {
  const double W = getWidth();
  const double H = getHeight();
  double MinX = W;
  double MaxX = -W;
  double MinY = H;
  double MaxY = -H;
  for (auto P : Positions) {
    MinX = std::min(MinX, P.x);
    MaxX = std::max(MaxX, P.x);
    MinY = std::min(MinY, P.y);
    MaxY = std::max(MaxY, P.y);
  }
  double HalfX = (MinX + MaxX) / 2;
  double HalfY = (MinY + MaxY) / 2;
  // Shift to (0, 0)
  for (auto &P : Positions) {
    P.x -= HalfX;
    P.y -= HalfY;
  }
  // Scale to min(W, H) x min(W, H)
  double Scale = std::min(W / (MaxX - MinX), H / (MaxY - MinY));
  for (auto &P : Positions) {
    P.x *= Scale;
    P.y *= Scale;
  }
}

std::vector<Point> FruchtermanReingold::genPosition() {
  const int N = getNumNode();
  const double K = std::max(1.5, sqrt(N));
  double T = InitTemp;
  std::vector<Point> Positions(N);
  genInitPos(Positions);
  for (int iter = 0; iter < NumIter; ++iter) {
    std::vector<Vec> Displacements(N, Vec(0, 0));
    for (int v = 0; v < N; ++v) {
      // Calculate repulsive force
      for (int u = v + 1; u < N; ++u) {
        Vec Diff = Positions[v] - Positions[u];
        double Norm = Diff.getNorm();
        Vec Unit = Diff * (1.0 / Norm);
        double Force = calRepulsiveForce(Norm, K);
        Displacements[v] += Unit * Force;
        Displacements[u] -= Unit * Force;
      }
      // Calculate attractive force
      for (int u : Graph[v]) {
        if (v >= u) {
          continue;
        }
        Vec Diff = Positions[v] - Positions[u];
        double Norm = Diff.getNorm();
        Vec Unit = Diff * (1.0 / Norm);
        double Force = calAttractiveForce(Norm, K);
        Displacements[v] -= Unit * Force;
        Displacements[u] += Unit * Force;
      }
    }
    // Limit the displacement to the temperature T
    for (int v = 0; v < N; ++v) {
      auto &Displacement = Displacements[v];
      double Norm = Displacement.getNorm();
      Positions[v] += Displacement * (std::min(Norm, T) / Norm);
      Positions[v].x =
          std::min(getWidth() / 2, std::max(-getWidth() / 2, Positions[v].x));
      Positions[v].y =
          std::min(getHeight() / 2, std::max(-getHeight() / 2, Positions[v].y));
    }
    // Reduce temperature T
    T = std::max(MinTemp, T * Delta);
  }
  scalePos(Positions);
  return Positions;
}

std::vector<std::vector<int>>
Visualization(int N, int M, std::vector<std::vector<int>> Edges) {
  std::vector<std::vector<int>> Graph(N);
  for (int i = 0; i < M; ++i) {
    Graph[Edges[i][0]].emplace_back(Edges[i][1]);
    Graph[Edges[i][1]].emplace_back(Edges[i][0]);
  }
  FruchtermanReingold FR(Graph, N * 1e4, N * 1e4);
  auto Positions = FR.genPosition();
  std::vector<std::vector<int>> Ret;
  for (auto P : Positions) {
    std::vector<int> Tmp;
    Tmp.emplace_back(P.x);
    Tmp.emplace_back(P.y);
    Ret.emplace_back(Tmp);
  }
  return Ret;
}

PYBIND11_MODULE(fruchterman_reingold, m) {
  m.doc() = "Graph Visualization";
  m.def("Visualization", &Visualization);
}