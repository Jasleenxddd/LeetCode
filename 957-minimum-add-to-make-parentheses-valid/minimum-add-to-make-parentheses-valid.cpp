class Solution {
public:
    int minAddToMakeValid(string s) {
        int num=0;
        int cnt=0;
        for(char ch:s){
            if(ch=='(') num++;
            else {
                if(num>0) num--;
                else cnt++;
            }
        } 
        cnt+= num;
        return cnt;
    }
};