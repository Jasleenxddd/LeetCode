class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mpp;
        int sum=0;
        int maxi=0;
        int l=0;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            sum+=nums[i];
            while(mpp[nums[i]]>1){
                sum-=nums[l];
                mpp[nums[l]]--;
                l++;
            } 
            maxi=max(sum, maxi);
        }
        return maxi;
    }
};