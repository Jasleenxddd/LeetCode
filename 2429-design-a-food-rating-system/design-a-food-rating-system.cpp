class FoodRatings {
public:
    unordered_map<string, string> f_c;
    unordered_map<string, set<pair<int, string>>> c_r_f;
    unordered_map<string, int> f_r;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0; i<n; i++){
            string food=foods[i];
            string c=cuisines[i];
            int r=ratings[i];
            c_r_f[c].insert({-r, food});
            f_c[food]=c;
            f_r[food]=r;
        }
    }
    
    void changeRating(string food, int newRating) {
        string c=f_c[food];
        int oldR=f_r[food];
        f_r[food]=newRating;
        c_r_f[c].erase({-oldR, food});
        c_r_f[c].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return begin(c_r_f[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */