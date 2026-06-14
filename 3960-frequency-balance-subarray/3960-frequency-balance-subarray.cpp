class Solution {
public:
    //Approach 1: TLE
    // bool isBalanced(unordered_map<int, int>&f){
    //     if(f.size() == 1) return true;
    //     set<int> s;
    //     for(auto& it: f) s.insert(it.second);
        
    //     if(s.size() != 2) return false;
    //     auto it = s.begin();
    //     int a = *it;
    //     it++;
    //     int b = *it;
    //     int mini = min(a,b);
    //     int maxi = max(a, b);
    //     return maxi == 2*mini;
        
    // }
    // int getLength(vector<int>& nums) {
    //     int ans = 1;
    //     int n = nums.size();
    //     for(int i = 0; i < n; i++){
    //         unordered_map<int, int> freq;
    //         for(int j = i; j < n; j++){
    //             freq[nums[j]]++;
    //             if(isBalanced(freq)) ans = max(ans, j-i+1);
    //         }
            
    //     }
    //     return ans;
        
    // }
     int getLength(vector<int>& nums) {
         int ans = 1;
         int n = nums.size();
         for(int  i = 0; i < n; i++){
             unordered_map<int, int> freq;
             unordered_map<int, int> freqCnt;
             for(int j = i; j<n; j++){
                int x = nums[j];
                 if(freq.count(x)){
                     freqCnt[freq[x]]--;
                     if(freqCnt[freq[x]] == 0) freqCnt.erase(freq[x]);
                 }
                 freq[x]++;
                 freqCnt[freq[x]]++;

                 if(freq.size() == 1) ans = max(ans, j-i+1);
                 else if(freqCnt.size() == 2){
                     auto it = freqCnt.begin();
                     int f1 = it->first;
                     int c1 = it->second;
                     it++;
                     int f2 = it->first;
                     int c2 = it->second;

                     int mini = min(f1, f2);
                     int maxi = max(f1, f2);

                     if(maxi == mini*2) ans = max(ans, j-i+1);
                 }
                 
             }
         }
         return ans;
     }
};