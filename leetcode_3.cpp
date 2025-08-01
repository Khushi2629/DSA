Given a string s, find the length of the longest substring without duplicate characters.



  class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>count(256,0);
        int first=0;
        int sec=0;
        int len=0;
        while(sec < s.size()){
            while(count[s[sec]]){
                count[s[first]]=0;
                first++;
            }
            count [s[sec]]=1;
            len=max(len, sec - first +1);
            sec++;
        }
        return len;

        
    }
};
