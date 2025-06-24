class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                int s=max(0,i-k);
                int e=min((int)nums.size()-1,i+k);
                for(int j=s;j<=e;j++){
                    ans.insert(j);
                }
            }
        }
        return vector<int>(ans.begin(),ans.end());
    }
};