class Solution {
public:
    int digSum(int num){
        int digSum = 0;
        while(num){
            int dig = num%10;
            digSum += dig;
            num /= 10;
        }
        return digSum;
    }
    int minElement(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = digSum(nums[i]);
        }
        return *min_element(nums.begin(), nums.end());
    }
    // sort(nums.begin(), nums.end());
    // return nums[0];
};