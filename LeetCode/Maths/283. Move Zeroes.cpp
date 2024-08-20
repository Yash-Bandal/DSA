class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int j = -1;

        for (size_t i{0}; i < n; i++)
        {
            if (nums[i] == 0)
            {
                j = i;
                break;
            }
        }
        
        if (j == -1)
        {
            return;
        }
        for (size_t i = j + 1; i < n; i++)
        {
            if (nums[i] != 0){
            
            swap(nums[i], nums[j]);
            j++;
            }
        }
    }
};


class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n=a.size();
         vector<int> temp;
    //copy non-zero elements
    //from original -> temp array:
    for (int i = 0; i < n; i++) {
        if (a[i] != 0)
            temp.push_back(a[i]);
    }

    // number of non-zero elements.
    int nz = temp.size();

    //copy elements from temp
    //fill first nz fields of
    //original array:
    for (int i = 0; i < nz; i++) {
        a[i] = temp[i];
    }

    //fill rest of the cells with 0:
    for (int i = nz; i < n; i++) {
        a[i] = 0;
    }


        
    }
};
