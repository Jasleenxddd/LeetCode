class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, 0);
        vector<bool> seen(26, false);
        int n=s.size();
        for(int i=0; i<n; i++) last[s[i]-'a']=i;
        stack<int> st;
        for(int i=0; i<n; i++){
            char ch=s[i];
            if(seen[ch-'a']) continue;
            while(!st.empty() && ch<st.top() && last[st.top()-'a']>i){
                seen[st.top()-'a']=false;
                st.pop();
            }
            st.push(ch);
            seen[ch-'a']=true;
            
        }
        string ans="";
            while(!st.empty()){
                ans+=st.top();
                st.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
    }
};