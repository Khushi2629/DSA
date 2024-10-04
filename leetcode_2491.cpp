You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

The chemistry of a team is equal to the product of the skills of the players on that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.














class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        long ans=0, target = skill[0]+ skill[n-1],val1,val2;
        int i=0,j=n-1;
        while(i<j)
        {
            val1=skill[i++], val2=skill[j--];
            if(val1+val2 !=target) return -1;
            ans+=(val1 * val2);
        }
        return ans;
        
    }
};
