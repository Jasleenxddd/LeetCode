class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int cnt=0;
        int end=0;
        for(int i=0; i<n-1; i++){
            maxi=max(maxi, i+nums[i]);
            if(i==end){
                cnt++;
                end=maxi;
            }
        }
        return cnt;
    }
};