#include <iostream>
#include <list>
#include <queue>
#include <stdexcept>
#include <vector>

#include "graph.hpp"

using namespace std;

list<int> Graph::topologicalSort() {
    auto indegree = [this]() {
        vector<int> ind(n, 0);

        for (auto i = 0; i < n; ++i) {
            for (auto k : g[i]) {
                ind[k]++;
            }
        }

        return ind;
    };

    vector<int> ind = indegree();

    list<int> output;

    int sz = 0;

    queue<int> q;
    for (auto i = 0; i < n; ++i) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        output.push_back(t);
        ++sz;

        for (auto i : g[t]) {
            --ind[i];

            if (ind[i] == 0) {
                q.push(i);
            }
        }
    }

    return output;
}
