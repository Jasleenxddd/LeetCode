class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> pref(n+1, 0);
        for(int i=0; i<n; i++) pref[i+1]=pref[i]^arr[i];
        vector<int> ans;
        for(auto it: queries){
            int left=it[0];
            int right=it[1];
            ans.push_back(pref[right+1]^pref[left]);
        }
        return ans;
    }
};