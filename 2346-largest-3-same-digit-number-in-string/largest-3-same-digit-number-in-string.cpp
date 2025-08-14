class Solution {
public:
    // string largestGoodInteger(string nums) {
    //     int l=0;
    //     int n=nums.size();
    //     string ans="";
    //     for(int r=0; r<n; r++){
    //         if(r-l+1>3) l++;
    //         if(r-l+1==3 && nums[l]==nums[l+1] && nums[l]==nums[l+2]){
    //             string str=nums.substr(l, 3);
    //             if(str>ans) ans=str;
    //         }
    //     }
        
    //     return ans;
    // }

    // optimized approach
    string largestGoodInteger(string nums) {
        int n=nums.size();
        string ans="";
        for(int l=0; l<=n-3; l++){
            if( nums[l]==nums[l+1] && nums[l]==nums[l+2]){
                string str=nums.substr(l, 3);
                if(str>ans) ans=str;
            }
        }
        
        return ans;
    }
};