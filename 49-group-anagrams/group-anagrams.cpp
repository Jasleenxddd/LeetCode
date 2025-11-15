class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // key: sorted version of a string
        // value: list of strings that match this sorted key (all anagrams)
        unordered_map<string, vector<string>> mpp;
        for(string s: strs){
            string key=s;
            sort(key.begin(), key.end());
            mpp[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto& e: mpp) res.push_back(e.second);
        return res;
    }
};