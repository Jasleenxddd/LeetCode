class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        if(st.find(endWord)==st.end()) return 0;
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endWord) return steps;
            for(int i=0;i<word.size();i++){
                string temp=word;
                for(char j='a';j<='z';j++){
                    temp[i]=j;
                    if(st.find(temp)!=st.end()){
                        q.push({temp,steps+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};