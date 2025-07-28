class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[i-1]) ans.push_back(nums[i]);
        }
        int cnt=0;
        for(int i=1;i<ans.size()-1;i++){
            if((ans[i]> ans[i-1] && ans[i]> ans[i+1]) || (ans[i]< ans[i-1] && ans[i]< ans[i+1])) cnt++; 
        }
        return cnt;
    }
};