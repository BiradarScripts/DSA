#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

struct Element {
    int weight;
    int node;
    int parent;

    // Constructor
    Element(int w, int n, int p) : weight(w), node(n), parent(p) {}
};

// Define a comparator for the priority queue
struct CompareElement {
    bool operator()(const Element& e1, const Element& e2) {
        // For min-heap, the smaller weight should come first
        return e1.weight > e2.weight;
    }
};

void prims(const vector<vector<pair<int, int>>>& adj, vector<int>& vis, vector<vector<pair<int, int>>>& mst, priority_queue<Element, vector<Element>, CompareElement>& pq, int src) {
    // vis[src] = 1;
    pq.push(Element(0, src, -1));

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        if (it.parent != -1) {
            mst[it.parent].push_back({it.node, it.weight});
            mst[it.node].push_back({it.parent, it.weight});
            vis[it.node]=1;
        }

        //very imortant step
        if(vis[it.node]){
            continue;
        }

        for (auto itt : adj[it.node]) {  // Fixed: should be `it.node` instead of `it.second`
            int node = itt.first;
            int weight = itt.second;
            if (!vis[node]) {
                pq.push(Element(weight, node, it.node));
            }
        }
    }
}

int main() {
    int n, m;  // Number of nodes and edges
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);  // Adjacency list
    vector<int> vis(n, 0);  // Visited array
    vector<vector<pair<int, int>>> mst(n);  // Minimum spanning tree

    // Read edges and build the adjacency list
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<Element, vector<Element>, CompareElement> pq;
    
    // Run Prim's algorithm from the source node 0
    prims(adj, vis, mst, pq, 0);

    // Print the MST edges
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " is connected to:\n";
        for (const auto& edge : mst[i]) {
            cout << "  Node " << edge.first << " with weight " << edge.second << '\n';
        }
    }

    return 0;
}
