//Pair
class Solution {
     struct compare {
        bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
            return p1.first < p2.first;
        }
    };

public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()){
            return {};
        }
      vector<pair<int,int>>arr1;
      for(int i =0;i<arr.size();i++){
          arr1.push_back(make_pair(arr[i],i));
      }
       sort(arr1.begin(), arr1.end(), compare());
      int rank =1 ;
      for(int i = 0 ;i<arr1.size()-1;i++){
          if(arr1[i].first!=arr1[i+1].first){
              arr[arr1[i].second]=rank;
              rank++;
          }else{
               arr[arr1[i].second]=rank;
          }
      }
       if (!arr1.empty()) {
            arr[arr1.back().second] = rank;
       }
      return arr;
    }
};

//Map
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map <int,int> mpp;
        for(auto& it : arr){
            mpp[it]++;
        }

        //ranking
        int rank=1;
        for(auto& it:mpp){
            it.second=rank;
            rank++;
        }

        vector<int> ans(arr.size());
        for(int i=0;i<arr.size();i++){
            ans[i]=mpp[arr[i]];
        }

return ans;
    }
};

/*
first loop:
map stores as 
mpp = {37: 1, 12: 2, 28: 1, 9: 1, 100: 1, 56: 1, 80: 1, 5: 1}

second loop while assigning rank
it is not unordered map so internal sorting
and we access elements in sorted order
if printed while iterating
mpp = {5: 1, 9: 1, 12: 2, 28: 1, 37: 1, 56: 1, 80: 1, 100: 1}

is output


Understanding the process:
Map construction (mpp): You store the count of each element in the map. Since std::map keeps the keys in sorted order, when you assign ranks, they are automatically assigned in ascending order of the keys.

Rank assignment: When you iterate over the map (for(auto& it : mpp)), you're assigning ranks based on the sorted order of the keys.

Generating the result (ans): Here's where it gets important! Instead of using the sorted order of the map, you generate the result vector (ans) by referring to the original order of the input array arr. For each element in arr, you look up its rank in the map (mpp[arr[i]]), and place it in the corresponding position in the result vector.

This ensures that the final output is in the same order as the original input array, not in the sorted order of the keys.

Step-by-step illustration:
Let's walk through it with an example:

Input:
arr = [40, 10, 20, 30]

Step 1: Map construction
We insert elements into the map (mpp). The map will be:

mpp = {10: 1, 20: 1, 30: 1, 40: 1}

Step 2: Rank assignment
Now we assign ranks based on the sorted keys:

mpp = {10: 1, 20: 2, 30: 3, 40: 4}

Step 3: Generate result vector (ans)
Now, instead of using the sorted keys, we iterate through the original input array arr and replace each element with its corresponding rank from the map:

For arr[0] = 40, mpp[40] = 4 → ans[0] = 4
For arr[1] = 10, mpp[10] = 1 → ans[1] = 1
For arr[2] = 20, mpp[20] = 2 → ans[2] = 2
For arr[3] = 30, mpp[30] = 3 → ans[3] = 3

Final Output:
ans = [4, 1, 2, 3]
*/
