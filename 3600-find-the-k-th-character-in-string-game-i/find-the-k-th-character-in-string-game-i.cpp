class Solution {
public:
    char kthCharacter(int k) {
        string start="a";
        while(start.length()<k){
            string temp="";
                for(char c:start){
                    if(c=='z') temp+='a';
                    else temp+=c+1;
                }
                start+=temp;
        }
        return start[k-1];
    }
};