#include <iostream>
#include <queue>
#include <vector>

#include "graph.hpp"

using namespace std;

vector<int> Graph::bfs(int s) {
    vector<int> output;

    vector<bool> visited(n, false);

    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        output.push_back(t);

        for (auto i : g[t]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return output;
}

