You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).

Return the largest possible value of num after any number of swaps.








class Solution {
public:
    int largestInteger(int num) {
        string s =to_string(num);
        for(int i=0;i < s.size();i++){
            bool even=(s[i]-'0') % 2==0;

            for(int j=i+1;j<s.size();j++){
                if(even==((s[j]-'0')%2==0)){
                    if(s[i]<s[j]){
                        swap(s[i],s[j]);
                    }
                }
            }
        }
        return stoi(s);
        
    }
};
