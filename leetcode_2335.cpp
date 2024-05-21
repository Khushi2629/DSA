You have a water dispenser that can dispense cold, warm, and hot water. Every second, you can either fill up 2 cups with different types of water, or 1 cup of any type of water.

You are given a 0-indexed integer array amount of length 3 where amount[0], amount[1], and amount[2] denote the number of cold, warm, and hot water cups you need to fill respectively. Return the minimum number of seconds needed to fill up all the cups.











class Solution {
public:
    int fillCups(vector<int>& amount) {
        int seconds = 0;
        priority_queue<int> pq;
        // pushing all three amount in max heap
        pq.push(amount[0]);
        pq.push(amount[1]);
        pq.push(amount[2]);
        // increase the seconds while any cup is left
        while(pq.top()>0){
            // check the 1st cup 
            int first;
            first = pq.top();
            pq.pop();
            int second;
            // if 2nd cup is left then fill both the cup which take one second
            if(pq.top()>0){
                second = pq.top();
                pq.pop();
            }
            else{
                // if only single type of cup is left than consider one second for each cup
                // and add it to the seconds 
                if(first>0)
                    seconds+=first;
                break;
            }
            pq.push(first-1);
            pq.push(second-1);
            seconds++;
        }
        return seconds;

        
    }
};
