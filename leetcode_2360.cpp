You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

Return the length of the longest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node.







class Solution {
public:
    int longestCycle(vector<int>& edges) 
    {
       
        vector<int>visited(edges.size(),0);
        vector<bool>globalVisited(edges.size(),0);
        int ans=-1;
        for(int i=0;i<edges.size();i++)
        {
            if (visited[i]==0)
            {
                int temp=dfs(visited,edges,i,0,globalVisited);
                if (temp!=0)
                {
                    ans=max(ans,temp);
                }
            }
        }
        return ans;    
    }
    int dfs(vector<int>&visited,vector<int>&edges,int i,int count,vector<bool>&globalVisited)
    {
        if (globalVisited[i])
        {
            return -1;
        }
        if (edges[i]==-1)
        {
            globalVisited[i]=1;
            return -1;
        }
        if (visited[i]!=0)
        {
            return count-visited[i]+1;
        }
        visited[i]=count+1;
        int ans= dfs(visited,edges,edges[i],count+1,globalVisited);
        visited[i]=0;
        globalVisited[i]=1;
        return ans;

    }
};
