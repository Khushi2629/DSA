You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.





class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        // Create a max-heap (priority queue) of pairs {score, original index}
        priority_queue<pair<int, int>> heap;
        for (int i = 0; i < n; i++) {
            heap.push({score[i], i});
        }
        
        // This will store the rank string for each athlete (at the original index)
        vector<string> rank(n);
        int place = 1;
        
        // Process the heap: highest score comes first.
        while (!heap.empty()) {
            int originalIndex = heap.top().second;
            heap.pop();
            
            if (place == 1) {
                rank[originalIndex] = "Gold Medal";
            } else if (place == 2) {
                rank[originalIndex] = "Silver Medal";
            } else if (place == 3) {
                rank[originalIndex] = "Bronze Medal";
            } else {
                rank[originalIndex] = to_string(place);
            }
            place++;
        }
        
        return rank;
    }
};



