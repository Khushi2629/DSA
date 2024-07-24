You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

A node u is an ancestor of another node v if u can reach v via a set of edges.









  class Solution {
    private:
    vector<vector<int>>adj,ans;
    void DFS(int curr,int par)
    {
        for(int child: adj[curr])
        {
            if(!ans[child].empty() && ans[child].back()==par)
            continue;
            ans[child].push_back(par);
            DFS(child,par);
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        ans.resize(n);
        for(vector<int> edge: edges)
        adj[edge[0]].push_back(edge[1]);
        for(int i=0;i<n;i++)
        DFS(i,i);

        return ans;
        
    }
};
