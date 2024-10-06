
//418 Contest
class Solution {
private:
    string toBinaryString(int num) {
        string binaryStr = bitset<32>(num).to_string();
        // convert each num to 32 it bin str
        /*
        eg 1 2 3
        1->'00000000000000000000000000000001'  //32 bit with leading 0s strings
        2->'00000000000000000000000000000010'
        3->'00000000000000000000000000000011'
        */
        binaryStr = binaryStr.substr(binaryStr.find('1'));
        // this removes leading zeroes..mhnje 8 bit rep la first 000 astat te kadhne 
        /*
        here 32 bit rep used so that big numebers can be handled ,,but we dont need 0s that are at first for small bumbers
        remvove
        1 = '1'
        2= '10'
        3 = '11'

        */
        return binaryStr;
    }

public:
    int maxGoodNumber(vector<int>& nums) {
        int maxVal=INT_MIN;
        //sort fot using all permutations possible
        sort(nums.begin(),nums.end());
        do{
            //concatanate
            string concatenateBinary="";
            for(int num : nums){
            //eazy pizy
            concatenateBinary += toBinaryString(num);
            }
            //reconvert string to decimal integer
            int deci=stoi(concatenateBinary,0,2);
            //max shodhne
            maxVal=max(maxVal,deci);
        }while(next_permutation(nums.begin(),nums.end()));  //do for all permutations
  return maxVal;
    }
};

/*
Sopa a
First 
arr=[1 2 3]
Step 1 :
convert each to binary without having leading zeroes number to string..see function carefully
  .make functio..pass each num tohrough for loop ...concatenate and store all in a var
  ..do this for each permutation 

  recall do while
1 = '1'
2= '10'
3 = '11'

Step 2:
Concatenate
                                    32 16 8 4 2 1 0
'1'+ '10'+'11'='11011'...           0  1  1 0 1 1 0   ..that is 1+2+8+16=26



Step 3:
--Like this for loop will generate different strings concatenated for each permutation of array


-- convert each concatenated binary string to decimal using stoi func u know this
stoi(11011) =27

--using max func..find maxVal using  the stoi converted each decimal 
(obvios logic the biggest binary string will be 11110..and thats 30..so maxVal will store 30)

-- using while and stl inbuilt
do this for all permutations..no need for calculating permuattion..use buildt in




Step 4:
you will find max permutation array =[3 1 2]
'11'+'1'+'10'='11110'..obvius logic jr sagle first 1 astil tr number motha asto basics

                                    32 16 8 4 2 1 0
'11'+'1'+'10'='11110'...            0  1  1 1 1 0 0   ..that is 2+4+8+16=30

stoi('1111'=30)

SiMpLe


*/
