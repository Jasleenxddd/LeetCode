class Solution {
public:
    int score(string& s, char i, char j, int val){
        stack<char> st;
        int pts=0;
        for(char it: s){
            if(!st.empty() && st.top()==i && it==j){
                st.pop();
                pts+= val;
            }else{
                st.push(it);
            }
        }
        string rem = "";
        while(!st.empty()){
            rem+= st.top();
            st.pop();
        }
        reverse(rem.begin(), rem.end());
        s= rem;
        return pts;
    }
    int maximumGain(string s, int x, int y) {
        int cnt=0;
        if(x>=y){
            cnt+=score(s, 'a', 'b', x);
            cnt+=score(s, 'b', 'a', y);
        }
        else{
            cnt+=score(s, 'b', 'a', y);
            cnt+=score(s, 'a', 'b', x);
        }
        return cnt;
    }
};