You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.





class Solution {
public:
    int spanningTree(int V, vector<vector<vector<int>>> adj)
    {
       int ans = 0;
       vector<int> vis(V, 0);
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       pq.push({0, 0}); // stores {wt, node}
       // In case you have to return the MST edges, take a priority queue of the form {wt, {node, parent}}
       while(!pq.empty()){
           int wt = pq.top().first;
           int node = pq.top().second;
           pq.pop();
           
           if(vis[node]) continue;
           else vis[node] = 1;
           ans+=wt;
           
           for(auto it: adj[node]){
               if(!vis[it[0]]){
                   pq.push({it[1], it[0]});
               }
           }
       }
       return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        //building the graph
        vector<vector<vector<int>>> adj(points.size());
        for(int i=0; i<points.size(); i++){
            for(int j=0; j<points.size(); j++){
                if(j!=i){
                    int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                    adj[i].push_back({j, dist});
                }
            }
        }
        // applying prim's algorithm
        return spanningTree(points.size(), adj);
    }
};
