class MovieRentingSystem {
public:
    // search: movie-> price, shop
    unordered_map<int, set<pair<int, int>>> mpp;
    // shop->movies
    unordered_map<int, vector<int>> smp;
    // price, shop, movie
    set<tuple<int, int, int>> rented;
    // shop->movie, price
    unordered_map<int, unordered_map<int, int>> ordmpp;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto& ent:entries){
            int movie=ent[1], price=ent[2],  shop=ent[0];  
            mpp[movie].insert({price, shop});
            smp[shop].push_back(movie);
            ordmpp[shop][movie]=price;
        }
    }
    
    vector<int> search(int movie) {
        int cnt=0;
        vector<int> res;
        if(!mpp.count(movie)) return res;
        // for(int i=0; i<mpp[movie].size(); i++){
        //     auto& [p, shop]= mpp[movie];
        //     res.push_back(shop);
        //     cnt++;
        //     if(cnt>=5) break;
        // }
        for(auto i=mpp[movie].begin();i!=mpp[movie].end() && cnt<5; i++){
            res.push_back(i->second);
            cnt++;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price=ordmpp[shop][movie];
        mpp[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price=ordmpp[shop][movie];
        rented.erase({price, shop, movie});
        mpp[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt=0;
        for(auto i=rented.begin();i!=rented.end() && cnt<5; i++){
            auto [price, shop, movie]=*i;
            res.push_back({shop, movie});
            cnt++;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */