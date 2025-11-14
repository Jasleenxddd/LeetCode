class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1=nums1.size();
        int r=n1-1;
        for(int i=0; i<n; i++){
            nums1[r]=nums2[i];
            r--;
        }
        sort(nums1.begin(), nums1.end());
    }
};