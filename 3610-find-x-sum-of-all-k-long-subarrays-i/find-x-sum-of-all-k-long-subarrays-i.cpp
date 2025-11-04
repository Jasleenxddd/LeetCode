class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> ans;
        // num, freq
        unordered_map<int, int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
            if(i>=k){
                int rem=nums[i-k];
                mpp[rem]--;
                if(mpp[rem]==0) mpp.erase(rem);
            }
            if(i>=k-1){
                vector<pair<int, int>> arr(mpp.begin(), mpp.end());
                sort(arr.begin(), arr.end(), [](auto &a, auto &b){
                    if(a.second==b.second) return a.first>b.first;
                    return a.second>b.second;
                });
                int sum=0;
                int cnt=0;
                for(auto & it: arr){
                    if(cnt==x) break;
                    sum+=it.first*it.second;
                    cnt++;
                }
                ans.push_back(sum);
            }
        }
        return ans;
    }
};