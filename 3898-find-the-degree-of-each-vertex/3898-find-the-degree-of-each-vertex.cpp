class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>deg;
        // for(int i =0; i <matrix.size(); i++){
        //     for(int j=0; j<matrix[0].size(); j++){

        //     }
        // }
        for(vector<int> v: matrix){
            deg.push_back(accumulate(v.begin(), v.end(), 0));
        }
        return deg;
    }
};