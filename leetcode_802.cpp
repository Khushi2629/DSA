There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.







class Solution {
public:

    bool dfs(int node, vector<int>& visited, vector<vector<int>>& graph){
        
        visited[node] = 2;
        
        
        for(auto it : graph[node]){
            if(!visited[it]){

                if(dfs(it, visited, graph) == true){
                    return true;
                }
            }
            
            else if(visited[it] == 2){
                return true;
            }
        }
        
        visited[node] = 1;
        return false;
        
    }
    
    
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V = graph.size();

        vector<int> visited(V, 0);
        
        for(int i = 0;i<V;i++){
            if(!visited[i]){
                dfs(i, visited, graph);
            }
        }

        vector<int> safe_nodes;
        
        for(int i = 0;i<V;i++){
            if(visited[i] == 1){
                safe_nodes.push_back(i);
            }
        }

        return safe_nodes;
    }
}; 
