class Solution {
public:
    string f(int n){
        string s=to_string(n);
        sort(s.begin(), s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string a=f(n);
        for(int i=0; i<31; i++){
            if(a==f(1<<i)) return true;
        }
        return false;
    }
};