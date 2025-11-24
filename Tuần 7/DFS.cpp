#include <iostream>
#include <vector>
using namespace std;

const int N = 100;
vector<int> adj[N];
int visited[N];

void dfs(int s) {
    stack<int> st;
    st.push(s);
    visited[s] = 1;

    while (!st.empty()) {
        int v = st.top();
        st.pop();

        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = 1;
                st.push(u);
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Đối với đồ thị vô hướng
    }

    int startNode;
    cin >> startNode;

    dfs(startNode);

    cout << "Cac dinh da duoc tham: ";
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
