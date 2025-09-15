class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st(brokenLetters.begin(), brokenLetters.end());
        int cnt=0;
        bool type=true;
        for(int i=0; i<text.length(); i++){
            if(st.count(text[i])) type=false;
            else if(text[i]==' '){
                if(type==true) cnt++;
                type=true;
            }
        }
        if(type) cnt++;
        return cnt;

    }
};