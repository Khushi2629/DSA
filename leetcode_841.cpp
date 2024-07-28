There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.









  class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> visited(n,0);
        visited[0]=1;
        queue<int>q;
        for(int i=0;i<rooms[0].size();i++){
            q.push(rooms[0][i]);
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            if(visited[t]==0){
                visited[t]=1;
                for(int i=0;i<rooms[t].size();i++){
                    q.push(rooms[t][i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                return false;
            }
        }
        return true;

        
    }
};
