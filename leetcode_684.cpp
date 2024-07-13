
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.





  class Solution {
public:

    vector<int>parent,size;
    int findParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void UnionBySize(int u,int v){
        int ulPu = findParent(u);
        int ulPv = findParent(v);

        if(ulPu==ulPv)return;
        else if(size[ulPu]>size[ulPv]){
            parent[ulPv] = ulPu;
            size[ulPu] += size[ulPv];
        }
        else{
            parent[ulPu] = ulPv;
            size[ulPv] += size[ulPu];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
        int last=-1;
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];

            if(findParent(u)!=findParent(v)){
                UnionBySize(u,v);
            }
            else{
                last=i;
            }
        }
        return {edges[last][0],edges[last][1]};
    }
};
  
