
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.







class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &e : times).    //The loop iterates over each edge in the times vector
        adj[e[0]].push_back({e[1],e[2]});     // adds the pair (v, w) to the list of edges for node u, where e[0] represents the strting node, e[1] represent ending node, e[2] represent the time taken.

        vector<int>dis(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;

        q.push({0,k});
        dis[k]=0;
        while(!q.empty())
        {
            int u=q.top().second;
            int d=q.top().first;
            q.pop();

            if(d>dis[u]) continue;
            for(auto & it:adj[u])
            {
                int v=it.first;
                int w=it.second;
                if(dis[v]>dis[u]+w)
                {
                    dis[v]=dis[u]+w;
                    q.push({dis[v],v});
                }
            }

        }

        int mini=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX) return -1;
            if(dis[i]>mini)mini=dis[i];
        }

        return mini;
        
    }
};
