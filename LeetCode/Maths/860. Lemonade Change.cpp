860. Lemonade Change

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5=0;  //count of 5 rs..paisa is paisa
        int c10=0;  //money money
        
        for(auto bill : bills){
            if(bill == 5){
                c5++;
            }
            else if(bill == 10 && c5>=1){
                c10++;
                c5--;
            }
            else if(bill == 20 && c10>=1 && c5>=1){
                c10--;
                c5--;
            }
            else if(bill ==20 && c5>=3){
                c5-=3;
            }
            else 
                return false;
            
        }
        return true;
    }
};
