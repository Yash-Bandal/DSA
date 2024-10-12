class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (auto num : nums) {
            //we use found flag to stop at the first candidate
            /*
            --for example  for prime 7 candidates 1 2 3 4 5 6 7
            --3 5 6 give OR result as 7
            --thus stop at first candidate found ie 3 and not 5 6 
            */
            bool found=false;
            //candidates are trial numbers upto the prime number
            //for prime  7 candidates are 1,2,3,4,5,6,7
            //thus when candidate trial for 3 we get 3 | 4 =7(see table below)
            //thus append 3
            for(int candidate=0;candidate <=num;candidate++){
                if((candidate | candidate+1) == num){
                    //append the candidates
                    ans.push_back(candidate);
                    found=true;
                    break;
                }

            }
            if(!found){
                //not found ..append -1
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

/*
example of binnaries -decimals

/*
Bitwise OR table example for ans[i] OR (ans[i] + 1)

1 OR 1+1 = 1 OR 2 = 3
2 OR 2+1 = 2 OR 3 = 3
3 OR 3+1 = 3 OR 4 = 7
4 OR 4+1 = 4 OR 5 = 5
5 OR 5+1 = 5 OR 6 = 7
6 OR 6+1 = 6 OR 7 = 7
7 OR 7+1 = 7 OR 8 = 15
8 OR 8+1 = 8 OR 9 = 9
9 OR 9+1 = 9 OR 10 = 11
10 OR 10+1 = 10 OR 11 = 11
11 OR 11+1 = 11 OR 12 = 15
12 OR 12+1 = 12 OR 13 = 13
13 OR 13+1 = 13 OR 14 = 15
14 OR 14+1 = 14 OR 15 = 15
15 OR 15+1 = 15 OR 16 = 31
*/
