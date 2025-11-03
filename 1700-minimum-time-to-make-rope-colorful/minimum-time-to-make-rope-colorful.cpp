class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int num=0;
        int cost=0;
        int maxi=neededTime[0];
        for(int i=1; i<colors.length(); i++){
            char prev=colors[i-1];
            char curr=colors[i];
            if(prev==curr){
                cost+=min(maxi, neededTime[i]);
                maxi=max(maxi, neededTime[i]);
            }
            else maxi=neededTime[i];
        }
        return cost;
    }
};