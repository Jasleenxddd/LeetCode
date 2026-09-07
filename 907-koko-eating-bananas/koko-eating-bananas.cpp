class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi=INT_MIN;
        for(int i=0; i<piles.size(); i++) maxi=max(maxi, piles[i]);
        return maxi;
    }
    long long calcHrs(vector<int>& piles, int hrly){
        long long ans=0;
        for(int i=0; i<piles.size(); i++){
            ans+=(piles[i]+hrly-1)/hrly;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=findMax(piles);
        while(left<=right){
            int mid=left+(right-left)/2;
            long long hrs=calcHrs(piles, mid);
            if(hrs<=h) right=mid-1;
            else left=mid+1;
        }
        return left;
    }
};