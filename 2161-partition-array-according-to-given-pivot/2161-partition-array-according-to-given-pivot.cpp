class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        if(n == 1) return nums;
        vector<int> R;
        int tarC = 0, l =0, sz = n;
        for(int x: nums){
            if(x < pivot) nums[l++] = x;
            else if (x>pivot) R.push_back(x), sz--;
            else tarC++;
        }
        auto it = nums.begin()+l;
        fill(it, it+tarC, pivot);
        copy(R.begin(), R.end(), it+tarC);
        return nums;


    }
};