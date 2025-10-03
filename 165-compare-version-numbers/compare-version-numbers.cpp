class Solution {
public:
    int compareVersion(string version1, string version2) {
        int s1=version1.length(), s2=version2.length();
        int i=0, j=0;
        while(i<s1 || j<s2){
            long long num1=0;
            while(i<s1 && version1[i]!='.'){
                num1=num1*10 + (version1[i]-'0');
                i++;
            }
            i++;

            long long num2=0;
            while(j<s2 && version2[j]!='.'){
                num2=num2*10+ (version2[j]-'0');
                j++;
            }
            j++;

            if(num1<num2) return -1;
            if(num1> num2) return 1;
        }
        return 0;
    }
};