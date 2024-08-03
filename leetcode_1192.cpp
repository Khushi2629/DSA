There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.






  class Solution {
public:

void dfs(int node,int parent,int &timer, vector<int> &disc, vector<int>&low, vector<vector<int>> &result, vector<int>adj[],vector<bool>&visited)
{
    visited[node]=true;
    disc[node]=low[node]=timer++;

    for(auto nbr: adj[node])
    {
        if(nbr==parent)
        continue;

        if(!visited[nbr])
        {
            dfs(nbr, node,timer,disc,low,result,adj,visited);
            low[node]=min(low[node],low[nbr]);

            if(low[nbr]>disc[node])
            {
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {
            low[node]=min(low[node],disc[nbr]);
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<int>adj[n];
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        int timer=0;
        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        int parent=-1;
        vector<bool>visited(n);

        vector<vector<int>> result;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,parent, timer,disc,low,result,adj,visited);
            }
        }
        return result;
        
    }
};
