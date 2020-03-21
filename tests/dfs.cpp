#include <catch2/catch.hpp>
#include <vector>

#include "graph.hpp"

using namespace std;

TEST_CASE("Depth First Search") {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 3);

    REQUIRE(g.dfs(2) == vector<int>{2, 0, 1, 3});
}
