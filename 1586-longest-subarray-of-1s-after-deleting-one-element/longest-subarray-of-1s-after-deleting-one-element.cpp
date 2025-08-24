class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int l=0, cnt=0;
        for(int r=0; r<n; r++){
            if(nums[r]==0) cnt++;
            while(cnt>1){
                if(nums[l]==0) cnt--;
                l++;
            }
            maxi=max(maxi, r-l);
        }
        return maxi;
    }
};