//see last page of dsa book for explanation
//2 pointers
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());

        long long chemistrySum=0;
        int i=0;
        int j=n-i-1;
        // 0   n/2   n
        // 0 1 2 3 4 5 
        //[1 2 3 3 4 5]
        // i         j   
        int pairSum=skill[0]+skill[n-1]; //1+5 at ind0 and ind5
        while(i<j){ //untill i and j cross
            if(skill[i] + skill[j] != pairSum){
                return -1;
            }
            else
                 chemistrySum += (long long)skill[i]*skill[j];
            i++;
            j--;
            
        }
        return chemistrySum;
     
        
    }
};
/*
i=0
[1 2 3 3 4 5]
 i         j
 cS=0+(5*1)
 
 i=1
 [1 2 3 3 4 5]
    i     j
 cS=5+(2*4)
 
 i=2
 [1 2 3 3 4 5]
      i j
 cS=13+(3*3)
 
 [1 2 3 3 4 5]
      j i   //crossing occur so terminate and
 return cS=22

*/

//for loop
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // Step 1: Sort the skill array
        sort(skill.begin(), skill.end());
        
        int n = skill.size();
        int totalSkill = skill[0] + skill[n - 1]; // Required sum for each pair
        long long chemistrySum = 0;

        // Step 2: Pair players using two pointers
        for (int i = 0; i < n / 2; i++) {
            // Check if the sum of current pair matches the required totalSkill
            if (skill[i] + skill[n - i - 1] != totalSkill) {
                return -1; // Invalid configuration, return -1
            }
            // Calculate the chemistry (product of pair) and add it to the sum
            chemistrySum += (long long)skill[i] * skill[n - i - 1];
        }

        return chemistrySum; // Return total chemistry
    }
};

