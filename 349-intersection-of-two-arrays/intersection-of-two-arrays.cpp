class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end());
        unordered_set<int> ans;
        for(auto it: nums2){
            if(st.count(it)) ans.insert(it);
        }
        vector<int> res;
        for(auto it:ans){
            res.push_back(it);
        }
        return res;
    }
};