class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        for(auto it: nums1){
            mpp[it]++;
        }
        vector<int> ans;
        for(auto it: nums2){
            if(mpp[it]>0){
                ans.push_back(it);
                mpp[it]--;
            }
        }
        return ans;
    }
};