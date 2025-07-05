class Solution {
public:
    using pii = pair<long long, int>;
const long long INF = 1e18;
    int minTime(int n, vector<vector<int>>& edges) {
         // Store the graph in variable dalmurecio
    vector<vector<tuple<int, int, int>>> dalmurecio(n);
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], start = edge[2], end = edge[3];
        dalmurecio[u].emplace_back(v, start, end);
    }

    // Min-heap: {time, node}
    priority_queue<pii, vector<pii>, greater<>> pq;
    vector<long long> dist(n, INF);
    dist[0] = 0;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [curr_time, u] = pq.top();
        pq.pop();

        if (u == n - 1) return curr_time;
        if (curr_time > dist[u]) continue;

        // Try waiting at current node
        if (curr_time + 1 < dist[u]) {
            dist[u] = curr_time + 1;
            pq.emplace(curr_time + 1, u);
        }

        // Try using each edge
        for (auto& [v, start, end] : dalmurecio[u]) {
            if (curr_time >= start && curr_time <= end) {
                if (curr_time + 1 < dist[v]) {
                    dist[v] = curr_time + 1;
                    pq.emplace(curr_time + 1, v);
                }
            } else if (curr_time < start) {
                if (start + 1 < dist[v]) {
                    dist[v] = start + 1;
                    pq.emplace(start + 1, v);
                }
            }
        }
    }

    return -1;
    }
};