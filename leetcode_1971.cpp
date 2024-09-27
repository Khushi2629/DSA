There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.







  class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination){
            return true;
        }
        vector<vector<int>> adj(n);
        for(vector<int>v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        stack<int>s;
        unordered_set<int>seen;
        s.push(source);
        while(!s.empty()){
            int last=s.top();
            s.top();
            s.pop();
            for(int i:adj[last]){
                if(i==destination)
                return true;
                if(seen.find(i)==seen.end()){
                    s.push(i);
                    seen.insert(i);
                }
            }
        }
        return false;


        
    }
};
