#pragma once

#include <vector>

#include "geometry.hpp"

class FruchtermanReingold {
private:
  const std::vector<std::vector<int>> Graph;
  const double Width;
  const double Height;
  const int NumIter;
  const double InitTemp;
  const double MinTemp;
  const double Delta;

  double calAttractiveForce(const double x, const double k) const {
    return x * x / k;
  }
  double calRepulsiveForce(const double x, const double k) const {
    return k * k / x;
  }
  void genInitPos(std::vector<Point> &Positions) const;

  void ScalePos(std::vector<Point> &Positions) const;

public:
  FruchtermanReingold(const std::vector<std::vector<int>> &Graph,
                      double Width = 1e8, double Height = 1e8,
                      int NumIter = 1000, double InitTemp = 1e3,
                      double MinTemp = 1.0, double Delta = 0.95)
      : Graph(Graph), Width(Width), Height(Height), NumIter(NumIter),
        InitTemp(InitTemp), MinTemp(MinTemp), Delta(Delta) {}

  double getWidth() const { return Width; }
  double getHeight() const { return Height; }
  double getArea() const { return Width * Height; }
  int getNumNode() const { return Graph.size(); }

  std::vector<Point> genPosition();
};