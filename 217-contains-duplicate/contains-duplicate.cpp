class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_set<int> st;
        // st.insert(nums[0]);
        // for(int i=1;i<nums.size();i++){
        //     if(st.count(nums[i])==0) st.insert(nums[i]);
        //     else return true;
        // }
        // return false;
        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size(); i++){
            if(nums[i]==nums[i-1]) return true;
        }
        return false;
        
    }
};