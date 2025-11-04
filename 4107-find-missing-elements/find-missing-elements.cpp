class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=1; i<nums.size(); i++){
            int small=nums[i-1];
            int large=nums[i];
            for(int j=small+1; j<large;  j++) ans.push_back(j);
        }
        return ans;
    }
};