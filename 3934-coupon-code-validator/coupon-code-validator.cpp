class Solution {
public:
    bool aphNum(string& s){
        if(s.empty()) return false;
        for(auto it: s){
            if(!((it>='A' && it<='Z') ||
                (it>='a' && it<='z') ||
                (it>='0' && it<='9') || it=='_')){
                    return false;
                }
        }
        return true;
    }
    
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        unordered_map<string, int> mpp={
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
        vector<pair<string, string>> valid;
        vector<string> ans;
        for(int i=0; i<n; i++){
            if(aphNum(code[i]) && isActive[i]==true && (businessLine[i]=="electronics" || businessLine[i]=="grocery" || businessLine[i]=="pharmacy" || businessLine[i]=="restaurant")){
                valid.push_back({businessLine[i], code[i]});
            }
        }
        sort(valid.begin(), valid.end(), [&](const auto& a, const auto& b){
            if(mpp[a.first]!=mpp[b.first]) return mpp[a.first]<mpp[b.first];
            return a.second<b.second;
        });
        for(auto& it: valid) ans.push_back(it.second);
        return ans;
    }
};