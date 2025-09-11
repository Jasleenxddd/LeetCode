class Solution {
public:
    string sortVowels(string s) {
        string t;
        int n=s.length();
        map<int, char> mpp;
        for(int i=0; i<n; i++){
            char ch=tolower(s[i]);
            if(ch =='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                mpp[i]=s[i];
            }
        }
        for(auto& it: mpp){
            t.push_back(it.second);
        }
        sort(t.begin(), t.end());

        int i=0;
        for(auto& it: mpp){
            s[it.first]=t[i];
            i++;
        }
        return s;
    }
};