class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev;
        unordered_set<int> res;
        for(auto it: arr){
            unordered_set<int> curr;
            curr.insert(it);
            for(auto i: prev){
                curr.insert(i|it);
            }
            prev=curr;
            res.insert(curr.begin(), curr.end());
        }
        return res.size();
    }
};