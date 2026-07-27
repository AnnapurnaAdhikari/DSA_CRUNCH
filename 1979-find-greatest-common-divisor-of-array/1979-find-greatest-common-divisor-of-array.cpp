class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a = nums[nums.size()-1];
        int b = nums[0];

        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};