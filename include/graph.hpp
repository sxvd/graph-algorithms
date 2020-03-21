#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>

class Graph {
  private:
    int n;
    std::vector<std::vector<int>> g;

  public:
    Graph(int number) : n(number), g(number) {}

    void addEdge(int from, int to) { g[from].push_back(to); }

    std::vector<int> bfs(int s);
    std::vector<int> dfs(int s);

    bool isBipartite();

    std::list<int> topologicalSort();
};

#endif
