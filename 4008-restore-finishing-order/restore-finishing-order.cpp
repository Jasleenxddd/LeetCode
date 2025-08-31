class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n=order.size();
        int m=friends.size();
        unordered_map<int, int> mpp;
        vector<int> ans(n, 0);
        for(int it=0; it<n; it++) mpp[order[it]]=it;
        for(int i=0; i<m; i++){
            int t=friends[i];
            if(mpp.find(t)!= mpp.end()){
                ans[mpp[t]]=t;
            }
        }
        ans.erase(remove(ans.begin(), ans.end(), 0), ans.end());
        return ans;
    }
};