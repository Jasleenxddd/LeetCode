class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n=expression.size();
        stack<char> st;
        for(int i=0; i<n; i++){
            if(expression[i]==',') continue;
            if(expression[i]==')'){
                vector<char> val;
                while(st.top()!='('){
                    val.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();

                if(op=='!') st.push(val[0]=='t'? 'f': 't');
                else if(op=='&'){
                    bool res=true;
                    for(auto ch:val){
                        if(ch=='f'){
                            res=false;
                            break;
                        }
                    }
                    st.push(res? 't': 'f');
                }
                else if(op=='|'){
                    bool res=false;
                    for(auto ch:val){
                        if(ch=='t'){
                            res=true;
                            break;
                        }
                    }
                    st.push(res? 't': 'f');
                }

            }
            else st.push(expression[i]);
        }
        return st.top()=='t';
    }
};