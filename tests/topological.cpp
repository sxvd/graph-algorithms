#include <catch2/catch.hpp>
#include <list>

#include "graph.hpp"

using namespace std;

TEST_CASE("Topological Ordering") {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    REQUIRE(g.topologicalSort() == list<int>{4, 5, 2, 0, 3, 1});
}
