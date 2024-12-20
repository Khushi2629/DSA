There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.







  class Solution {
public:
    bool check(int start,vector<vector<int>>& adj,vector<int>& color) {
        queue<int>q;
        color[start]=0;
        q.push(start);
        while(!q.empty()){
            int prev=q.front();
            q.pop();
            for(auto curr: adj[prev]){
                if(color[curr]==-1){
                    color[curr]=!color[prev];
                    q.push(curr);
                }
                else if(color[curr]==color[prev]) return false;
            }
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& adj){
        int n=adj.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1 && !check(i,adj,color)) return false;
        }
        return true;
    }
};
