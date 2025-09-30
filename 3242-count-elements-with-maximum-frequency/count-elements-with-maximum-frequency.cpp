class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        int maxi=0;
        for(auto& it: mpp) maxi=max(maxi, it.second);
        int ans=0;
        for(auto& it: mpp){
            if(it.second==maxi) ans+=it.second;
        }
        return ans;
    }
};