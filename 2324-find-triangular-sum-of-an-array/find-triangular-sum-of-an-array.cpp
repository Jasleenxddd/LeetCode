class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=n-1; i>=0; i--){
            vector<int> temp(i, 0);
            for(int j=0; j<i; j++){
                temp[j]=(nums[j] + nums[j+1]) % 10;
            }
            nums=temp;
        }
        return nums[0];
    }
};