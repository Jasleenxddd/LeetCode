class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=1; i<n; i++){
            for(int j=i+1; j<n; j++){
                int cost=nums[0]+nums[i]+nums[j];
                ans=min(ans, cost);
            }
        }
        return ans;
    }
};