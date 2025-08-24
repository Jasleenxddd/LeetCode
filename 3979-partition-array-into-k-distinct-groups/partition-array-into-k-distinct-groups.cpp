class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> mpp;
        if(n%k!=0) return false;
        for(int i=0; i<n; i++) mpp[nums[i]]++;
        for(auto it: mpp){
            if(it.second> n/k) return false;
        }
        return true;
    }
};