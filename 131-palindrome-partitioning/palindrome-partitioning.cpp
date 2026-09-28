class Solution {
public:
    bool check(int left, int right, string& s){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;


    }
    void palin(int index, string& s, vector<vector<string>>& result, vector<string>& part){
        if(index==s.length()){
            result.push_back(part);
            return;
        }
        for(int i=index; i<s.length(); i++){
            if(check(index, i, s)){
                part.push_back(s.substr(index, i-index+1));
                palin(i+1, s, result, part);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> res;
        palin(0,s,result,res);
        return result;
    }
};