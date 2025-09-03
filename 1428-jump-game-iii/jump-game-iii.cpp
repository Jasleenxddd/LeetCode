class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(start);
        vis[start]=true;
        while(!q.empty()){
            int ind=q.front();
            q.pop();
            if(arr[ind]==0) return true;

            // right
            int r=ind+arr[ind];
            if(r<n && !vis[r]){
                vis[r]=true;
                q.push(r);
            }
            // left
            int l=ind-arr[ind];
            if(l>=0 && !vis[l]){
                q.push(l);
                vis[l]=true;
            }
        }
        return false;
    }
};