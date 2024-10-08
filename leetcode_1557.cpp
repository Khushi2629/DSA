Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.






  class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto& it : edges){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(adj[i].empty()){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};
