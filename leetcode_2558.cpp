You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

Choose the pile with the maximum number of gifts.
If there is more than one pile with the maximum number of gifts, choose any.
Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
Return the number of gifts remaining after k seconds.




  lass Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>p;
        for(int i=0;i<gifts.size();i++)
        {
            p.push(gifts[i]);
        }
        while(k>0)
        {
            int temp=p.top();
            p.pop();
            p.push(sqrt(temp));
            k--;
        }
        long long ans=0;
        while(!p.empty())
        {
            ans+=p.top();
            p.pop();
        }
        return ans;
        
    }
};
