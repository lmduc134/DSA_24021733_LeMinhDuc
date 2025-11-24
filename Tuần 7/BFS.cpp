#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 100;
vector<int> adj[N];
int visited[N];

void bfs(int s) {
    queue<int> q;
    visited[s] = 1;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = 1;
                q.push(u);
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
        adj[v].push_back(u);
    }

    bfs(1);

    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            cout << "Node " << i << " is reachable from node 1." << endl;
        } else {
            cout << "Node " << i << " is not reachable from node 1." << endl;
        }
    }

    return 0;
}
