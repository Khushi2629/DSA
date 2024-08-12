Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] is the distance from index i to the closest occurrence of character c in s.

The distance between two indices i and j is abs(i - j), where abs is the absolute value function.







class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            if(s[i]==c) ans.push_back(i);
        }
        vector<int>occurance(s.size());
        for(int i=0;i<s.size();i++){
            if(s[i]==c){
                occurance[i]=0;
            }
            else{
                int val=INT_MAX;
                for(int k=0;k<ans.size();k++){
                    val=min(val,abs(i-ans[k]));
                }
                occurance[i]=val;
            }
        }
        return occurance;
        
    }
};
