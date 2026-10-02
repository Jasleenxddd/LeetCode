class Solution {
public:
    void addString(vector<string>& result, string current,int open ,int close, int n){
        if(current.length()==n*2){
            result.push_back(current);
            return;
        }
        if(open<n) addString(result, current+"(", open+1, close, n);
        if(close<open) addString(result, current+")", open, close+1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        addString(result,"",0,0,n);
        return result;
    }
};