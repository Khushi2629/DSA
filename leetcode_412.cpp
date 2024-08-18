Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.







  class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans;
        int count;
        for(int i=1;i<=n;i++){
            if(i%15==0 ){
                ans.push_back("FizzBuzz");
            }
            else if(i%3==0){
                ans.push_back("Fizz");
            }
            else if(i%5==0){
                ans.push_back("Buzz");
            }
            else{
                ans.push_back(to_string(i)); // converting to string as i is an integer
            }

        }
        return ans;

        
    }
};