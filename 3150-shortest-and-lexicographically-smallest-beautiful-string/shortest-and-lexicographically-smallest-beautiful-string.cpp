class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        vector<int> store;
        for(int i=0; i<n; i++){
            if(s[i]=='1') store.push_back(i);
        }
        if(store.size()<k) return "";
        int maxi=INT_MAX;
        int bestSt=-1;
        for(int i=0; i+k-1<store.size(); i++){
            int start=store[i];
            int e=store[i+k-1];
            int len=e-start+1;
            if(len<maxi){
                maxi=len;
                bestSt=start;
            }
            else if(len==maxi){
                string curr=s.substr(start, len);
                string best=s.substr(bestSt, maxi);
                if(curr<best) bestSt=start;
            }
        }
        return s.substr(bestSt, maxi);
    }
};