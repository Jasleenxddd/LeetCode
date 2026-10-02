class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt=0;
        int n=arr.size();
        for(int i=0; i<n; i++){
            int x=0;
            for(int k=i; k<n; k++){
                x^=arr[k];
                if(x==0) cnt+=k-i;
            }
        }
        return cnt;
    }
};