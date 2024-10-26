We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.






  class Solution {
public:

bool bfs(vector<vector<int>> &adj,vector<int> &color,int node){
    queue<int>q;
    q.push(node);
    color[node]=1;
    while(!q.empty()){
        int p=q.front();
        q.pop();

        for(auto i: adj[p]){
            if(color[i]==color[p]){
                return false;

            }
            if(color[i]==-1){
                q.push(i);
                color[i]=1-color[p];
            }
        }
    }
    return 1;
}
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        vector<int>color(n+1,-1);
        for(auto i: dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!bfs(adj,color,i))
                return 0;
            }
        }
        return true;
       
            
        
        
    }
};
