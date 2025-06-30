class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0, ans=0;
        for(int r=1;r<nums.size();r++){
            if(nums[r]-nums[l]==1) ans=max(ans,r-l+1);
            while(nums[r]-nums[l]>1) l++;
        }
        return ans;
    }
};