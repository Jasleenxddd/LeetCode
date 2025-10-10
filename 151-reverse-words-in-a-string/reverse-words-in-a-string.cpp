class Solution {
public:
    string reverseWords(string s) {\
        // removing spaces
        stringstream ss(s);
        string word;
        vector<string> words;

        // extracting next word from stream
        while(ss>> word){
            words.push_back(word);
        }
        // reversing words
        reverse(words.begin(), words.end());
        string res;
        for(int i=0; i<words.size(); i++){
            if(i>0) res+=' ';
            res+=words[i];
        }
        return res;

        // int left=0;
        // int right=s.length()-1;
        // while(left<=right && s[left]==' '){
        //     left++;
        // }
        // while(left<=right && s[right]==' '){
        //     right--;
        // }
        // string temp="";
        // string ans="";
        // while(left<=right){
        //     char ch=s[left];
        //     if(ch!=' '){
        //         temp+=ch;
        //     }
        //     else if(ch==' '){
        //         if(temp!=""){
        //             if(ans!=""){
        //             ans=temp+ " "+ans;
        //         }
        //         else{
        //             ans=temp;
        //         }
        //         temp="";
        //         }
        //         while(left+1<=right && s[left+1]==' '){
        //             left++;
        //         }
        //     }
        //     left++;
        // }
        // if(temp!=""){
        //     if(ans!=""){
        //         ans=temp+" "+ans;
        //     }
        //     else{
        //         ans=temp;
        //     }

        // }
        // return ans;
    }
};