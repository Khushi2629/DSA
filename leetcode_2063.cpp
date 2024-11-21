Given a string word, return the sum of the number of vowels ('a', 'e', 'i', 'o', and 'u') in every substring of word.

A substring is a contiguous (non-empty) sequence of characters within a string.

Note: Due to the large constraints, the answer may not fit in a signed 32-bit integer. Please be careful during the calculations.





 class Solution {
public:
    long long countVowels(string word) {
        long long int ans = 0,k=0;
        for(int i = 0; i < word.length(); i++){
            if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'){
                k += (i+1);
                ans = ans+k;
            }else{
                ans = ans+k;
            }
           
        }
        return ans;
    }
}; 
