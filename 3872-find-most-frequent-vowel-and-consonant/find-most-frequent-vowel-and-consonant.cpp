class Solution {
public:
    int maxFreqSum(string s) {
        int maxiV=0, maxiC=0;
        unordered_map<char, int> v, c;
        for(int i=0; i<s.length(); i++){
            char ch=s[i];
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                v[ch]++;
                maxiV=max(maxiV, v[ch]);
            }
            else{
                c[ch]++;
                maxiC=max(maxiC, c[ch]);
            }
        }
        // for(int i=0; i<s.length(); i++){
        //     mpp[s[i]]++;
        // }  
        // for(auto& it: mpp){
        //     if(it.first=='a' || it.first=='e' || it.first=='i' || it.first=='o' || it.first=='u')
        //         maxiV=max(maxiV, it.second);
        //     else   
        //         maxiC=max(maxiC, it.second);
        // }
        return maxiV+maxiC;
    }
};