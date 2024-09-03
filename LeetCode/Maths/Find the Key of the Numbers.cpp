class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string str1=convFourDig(num1);
        string str2=convFourDig(num2);
        string str3=convFourDig(num3);

        string key="";

        for(int i=0;i<4;i++){
            char minDig=min({str1[i] ,str2[i],str3[i] });
            key+=minDig;
        }
        return stoi(key);



    }

    private: 
    string convFourDig(int num){
        string str=to_string(num);
       
       while(str.length() < 4){
        str= "0"+str;  //append frm back
       }
       return str;
    }
};
