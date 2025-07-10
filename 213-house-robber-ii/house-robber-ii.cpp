class Solution {
public:
    int spc(vector<int>& nums){
        int n=nums.size();
        int prev=nums[0];
        int prev1=0;
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=prev1;
            int notPick=prev;
            int curr=max(pick,notPick);
            prev1=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> tmp1, tmp2;
        for(int i=0;i<n;i++){
            if(i!=0) tmp1.push_back(nums[i]);
            if(i!=n-1) tmp2.push_back(nums[i]);
        }
        return max(spc(tmp1), spc(tmp2));
    }
};