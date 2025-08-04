class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> map;
        int l=0,r=0,len=0;
        for(r=0;r<fruits.size();r++){
            map[fruits[r]]++;
            if(map.size()>2){
                map[fruits[l]]--;
                if(map[fruits[l]]==0){
                    map.erase(fruits[l]);
                }
                l++;
            }
            if(map.size()<=2){
                len=max(len,r-l+1);
            }
        }
        return len;
    }
};