Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".







  class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string ans="";
        string a=strs[0],m=strs[n-1];
        for(int i=0;i<a.size();i++){
            if(a[i]==m[i]){
                ans+=a[i];
            }
            else break;

        }
        return ans;





        
    }
};
