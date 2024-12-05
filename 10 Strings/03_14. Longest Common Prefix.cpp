class Solution {
public:
    string
    longestCommonPrefix(vector<string>& strs) { // its a vector so can access
                                                // each word with index
        //["Hi" "ABCS"]
        // 0     1
        if (strs.empty()) {
            return "";
        }
        string prefix = strs[0];
        for (string s : strs) {
            while (s.find(prefix) != 0)
                prefix = prefix.substr(0, prefix.length() - 1);
        }
        return prefix;
    }
};

//====================My Try=======================

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) { 
        string prefix=strs[0];
        if(strs.empty()){
            return "";
        }  //ie no string prefix ..when no string inside
        for(auto s : strs){
            while(s.find(prefix) != 0){
                prefix=prefix.substr(0,prefix.length()-1);
            }
            /*
              //1st iteration 0  flower.find(flower) !=0..false..so next string check

              //2nd
              flower.find(flow) !=0..True
              * Iteration 1:
             * Comparing prefix = "flower" with s = "flow"
             * "flower".find("flower") != 0 → False
             * prefix = "flower".substr(0, 6 - 1) → "flowe"
             * "flow".find("flowe") != 0 → False
             * prefix = "flowe".substr(0, 5 - 1) → "flow"
             * "flow".find("flow") == 0 → True
             * Final prefix after this iteration: "flow"
             
             * Iteration 2:
             * Comparing prefix = "flow" with s = "flight"
             * "flight".find("flow") != 0 → False
             * prefix = "flow".substr(0, 4 - 1) → "flo"
             * "flight".find("flo") != 0 → False
             * prefix = "flo".substr(0, 3 - 1) → "fl"
             * "flight".find("fl") == 0 → True
             * Final prefix after this iteration: "fl"
            */
        }
        return prefix;
     
    }
};
/**
 * Iteration 1:
 * Comparing prefix = "flower" with s = "flow"
 * "flower".find("flower") != 0 → False
 * prefix = "flower".substr(0, 6 - 1) → "flowe"
 * "flow".find("flowe") != 0 → False
 * prefix = "flowe".substr(0, 5 - 1) → "flow"
 * "flow".find("flow") == 0 → True
 * Final prefix after this iteration: "flow"
 */

/**
 * Iteration 2:
 * Comparing prefix = "flow" with s = "flight"
 * "flight".find("flow") != 0 → False
 * prefix = "flow".substr(0, 4 - 1) → "flo"
 * "flight".find("flo") != 0 → False
 * prefix = "flo".substr(0, 3 - 1) → "fl"
 * "flight".find("fl") == 0 → True
 * Final prefix after this iteration: "fl"
 */
