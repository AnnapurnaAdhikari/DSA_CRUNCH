class Solution {
public:
    // bool eqArr(vector<int>& nums){
    //     for(int i = 0; i < nums.size()-1; i++){
    //         if(nums[i] != nums[i+1]) return false;
    //     }
    //     return true;
    // }
    int minMoves(vector<int>& nums) {
        int moves = 0;
        int mini = *min_element(nums.begin(), nums.end());
        for(int  i = 0; i < nums.size(); i++){
            moves += nums[i] - mini;
        }
        return moves;


        // int moves = 0;
        // while(!eqArr(nums)){
        //     sort(nums.begin(), nums.end());
        //     int maxi = *max_element(nums.begin(), nums.end());
        //     int i = 0;
        //     while(nums[i] < maxi && i < nums.size()){
        //         nums[i]++;
        //         i++;
        //     }
        //     moves++;
        // }
        // return moves;
    }
};