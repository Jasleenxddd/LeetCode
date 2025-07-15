class Solution {
public:
    bool isValid(string word) {
        bool v=false;
        bool c=false;
        if(word.length()<3) return false;
        for(auto it: word){
            if(!isalnum(it)) return false;
            if(isalpha(it)){
                char l=tolower(it);
                if(l=='a' || l=='e' || l=='i' || l=='o' || l=='u') v=true;
                else c=true;
            }
        }
        return v && c;
    }
};