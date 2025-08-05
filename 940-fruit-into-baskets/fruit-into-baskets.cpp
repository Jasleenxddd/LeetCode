class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int l=0, len=0;
        for(int r=0; r<fruits.size();r++){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            if(mpp.size()<=2) len=max(len, r-l+1);
        }
        return len;
    }
};