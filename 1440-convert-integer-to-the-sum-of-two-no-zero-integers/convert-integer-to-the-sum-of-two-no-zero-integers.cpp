class Solution {
public:
    bool f(int i){
        while(i>0){
            if(i%10== 0) return true;
            i=i/10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> arr;
        int a, b;
        if(n<=2) a=1;
        else a=2;
        b=n-a;
        while(f(a) || f(b)){
            a++;
            b=n-a;
        }
        arr.push_back(a);
        arr.push_back(b);
        return arr;
    }
};