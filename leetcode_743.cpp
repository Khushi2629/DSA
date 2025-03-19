
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.





class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);  // Create adjacency list

        for (auto &e : times)  // FIXED: Removed the dot `.`
            adj[e[0]].push_back({e[1], e[2]}); 

        vector<int> dis(n+1, INT_MAX);  // Distance vector initialized with INT_MAX
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        q.push({0, k});  // Start from node k
        dis[k] = 0;

        while (!q.empty()) {
            int u = q.top().second;
            int d = q.top().first;
            q.pop();

            if (d > dis[u]) continue;  // If a better distance is already found

            for (auto &it : adj[u]) {
                int v = it.first;
                int w = it.second;
                if (dis[v] > dis[u] + w) {  // Relaxation step
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }

        int mini = 0;  // FIXED: Initialize with 0, not INT_MIN
        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) return -1;  // If any node is unreachable
            mini = max(mini, dis[i]);  // Track the longest shortest time
        }

        return mini;
    }
};


