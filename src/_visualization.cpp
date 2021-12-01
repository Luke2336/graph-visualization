#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "fruchterman_reingold.h"

namespace py = pybind11;

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
  }
  return Ret;
}

PYBIND11_MODULE(_visualizaion, m) {
  m.doc() = "Graph Visualization";
  m.def("Visualization", &Visualization);
}
/*
g++ -O3 -Wall -shared -std=c++17 -undefined dynamic_lookup `python3 -m pybind11 --includes` _visualization.cpp -o _visualization`python3-config --extension-suffix`
*/