#include <stack>
#include <vector>

#include "graph.hpp"

using namespace std;

vector<int> Graph::dfs(int s) {
    vector<int> output;

    vector<bool> visited(n, false);

    stack<int> st;
    st.push(s);

    while (!st.empty()) {
        auto t = st.top();
        st.pop();
        visited[t] = true;
        output.push_back(t);

        for (auto i : g[t]) {
            if (!visited[i]) {
                st.push(i);
            }
        }
    }

    return output;
}
