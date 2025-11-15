class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt=0;
        int n=arr.size();
        int i=0;
        int maxi=arr[0];
        while(i<n){
            maxi=max(maxi, arr[i]);
            if(maxi==i) cnt++;
            i++;
        }
        return cnt;
    }
};