There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.






  class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>price(n,INT_MAX);
        price[src]=0;
        queue<pair<int,pair<int, int>>>q;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stop=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();

            if(stop>k){
                continue;
            }
            for(auto it: adj[node]){
                if(stop<=k && cost+it.second<price[it.first]){
                    price[it.first]=cost+it.second;
                    q.push({stop+1,{it.first,cost+it.second}});
                }
            }
        }
        if(price[dst]==INT_MAX) return -1;
        return price[dst];
        
    }
};
