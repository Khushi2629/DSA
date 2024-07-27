Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).




class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int end=graph.size()-1;
        vector<vector<int>> output;
        vector<int>path;
        dfs(graph,0,end,path,output);
        return output;
        
    }

    private:
    void dfs(const vector<vector<int>>& graph,int node,int end, vector<int>& path, vector<vector<int>>& output) {
        path.push_back(node);

        if(node==end) {
            output.push_back(path);
        } else{
            for(int n: graph[node]) {
                dfs(graph,n,end,path,output);

            }
        }

        path.pop_back();
    }
};
