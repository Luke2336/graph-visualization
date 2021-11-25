#include <iostream>
#include <vector>

#include "fruchterman_reingold.hpp"

int main() {
  int NumNode;
  int NumEdge;
  std::cin >> NumNode >> NumEdge;
  std::vector<std::vector<int>> Graph(NumNode);
  for (int i = 0; i < NumEdge; ++i) {
    int a, b;
    std::cin >> a >> b;
    Graph[a].emplace_back(b);
    Graph[b].emplace_back(a);
  }
  FruchtermanReingold FR(Graph, NumNode * 1e4, NumNode * 1e4);
  auto Positions = FR.genPosition();
  for (auto P : Positions) {
    std::cout << (int)P.x << ' ' << (int)P.y << '\n';
  }
  return 0;
}
