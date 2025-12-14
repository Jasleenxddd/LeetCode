class Solution {
public:
    int numberOfWays(string corridor) {
        const int mod=1e9+7;
        vector<int> seats;
        for(int i=0; i<corridor.length(); i++){
            if(corridor[i]=='S') seats.push_back(i);
        }
        int cnt=seats.size();
        if(cnt==0 || cnt%2!=0) return 0;

        long long ans=1;
        for(int i=2; i<cnt; i+=2){
            int prev=seats[i-1];
            int curr=seats[i];
            int plants=curr-prev-1;
            ans=(ans*(plants+1))%mod;
        }
        return ans;
    }
};