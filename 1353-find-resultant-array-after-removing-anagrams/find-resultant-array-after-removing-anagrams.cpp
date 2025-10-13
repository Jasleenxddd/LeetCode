class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<string> res;
        string p="";
        for(auto it: words){
            string a=it;
            sort(a.begin(), a.end());
            if(a!=p){
                res.push_back(it);
                p=a;
            }
        }
        return res;
    }
};