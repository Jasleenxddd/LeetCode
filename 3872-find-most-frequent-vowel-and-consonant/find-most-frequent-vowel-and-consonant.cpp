class Solution {
public:
    int maxFreqSum(string s) {
        int v=0, c=0;
        int maxiV=0, maxiC=0;
        unordered_map<char, int> mpp;
        for(int i=0; i<s.length(); i++){
            mpp[s[i]]++;
        }  
        for(auto& it: mpp){
            if(it.first=='a' || it.first=='e' || it.first=='i' || it.first=='o' || it.first=='u')
                maxiV=max(maxiV, it.second);
            else   
                maxiC=max(maxiC, it.second);
        }
        return maxiV+maxiC;
    }
};