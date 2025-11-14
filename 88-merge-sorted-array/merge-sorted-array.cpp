class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Time complexity: O((m+n)(log(m+n)))
        // int n1=nums1.size();
        // int r=n1-1;
        // for(int i=0; i<n; i++){
        //     nums1[r]=nums2[i];
        //     r--;
        // }
        // sort(nums1.begin(), nums1.end());

        // optimal code with TC: O(m+n)
        int n1=m-1;
        int n2=n-1;
        int l=n+m-1;
        while(n1>=0 && n2>=0){
            if(nums1[n1]>=nums2[n2]){
                nums1[l]=nums1[n1];
                n1--;
                l--;
            }
            else{
                nums1[l]=nums2[n2];
                n2--;
                l--;
            }
        }
        while(n2>=0){
            nums1[l]=nums2[n2];
            l--;
            n2--;
        }
    }
};