In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.







class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>m;
        for(int i=0;i<trust.size();i++){
            m[trust[i][0]]=-1;
            m[trust[i][1]]++;
        }
        int ans=-1;

        for(int i=1;i<=n;i++){
            if(m[i]==n-1)
            ans=i;
        }
        return ans;
        
    }
};
