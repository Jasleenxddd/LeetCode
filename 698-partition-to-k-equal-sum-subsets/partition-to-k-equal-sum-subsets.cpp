class Solution {
public:
    bool f(vector<int>& nums, int k, int target, int currSum, int mask){
        if(k==1) return true;
        int prev=-1;
        if(currSum==target) return f(nums, k-1, target, 0, mask);
        for(int i=0; i<nums.size(); i++){
            if(mask&(1<<i)) continue;
            if(nums[i]==prev) continue;
            if(currSum+nums[i]>target) continue;
            mask=mask|(1<<i);
            if(f(nums, k, target, currSum+nums[i], mask)) return true;
            mask=mask& ~(1<<i);
            prev=nums[i];
            if(currSum==0) return false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total=0;
        for(auto it: nums) total+=it;
        if(total%k!=0) return false;
        int target=total/k;
        for(auto it: nums){
            if(it> target) return false;
        }
        sort(nums.rbegin(), nums.rend());
        return f(nums, k, target, 0, 0);
    }
};