//Brute TLE

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        long long score=0;
     while(k!=0){
         sort(nums.begin(),nums.end());
         int maxEle=nums.back();
         score+=maxEle;
         nums.back()=ceil(maxEle/3.0);
         
         k--;
     }
        return score;
        
    }
};


//PQ
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int> pq;
        long long score=0;
        
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        
        while(k--){
            int maxEle=pq.top();
            score+=maxEle;
            pq.pop();
            //dont do pq.top()=ceil(maxEle/3.0)..pq.top just acces val not update
            pq.push(ceil(maxEle/3.0)); //if not used 3.0 and used  ...we get small changed output like score 16..instead of 17..thus use 3.0
            
        }
        return score;
        
    }
};


class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // Max heap to get the largest element efficiently
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        
        long long score = 0;
        
        // Perform the operation k times
        while (k--) {
            int maxElement = maxHeap.top();
            maxHeap.pop();
            
            // Add the largest element to the score
            score += maxElement;
            
            // Push the updated value (ceil(maxElement / 3)) back into the heap
            maxHeap.push(ceil(maxElement / 3.0));
        }
        
        return score;
    }
};
