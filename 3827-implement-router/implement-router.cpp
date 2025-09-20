class Router {
public:
    int limit;
    queue<tuple<int, int, int>> q;
    // timestamp
    set<tuple<int, int, int>> st;
    unordered_map<int, vector<int>> mpp;
    Router(int memoryLimit) {
        limit=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(st.count({source, destination, timestamp})) return false;
        if(q.size()>=limit){
            auto old=q.front();
            q.pop();
            auto [s, d, t]=old;
            st.erase(old);
            if(!mpp.empty()) mpp[d].erase(mpp[d].begin());  
        }
        st.insert({source, destination, timestamp});
        q.push({source, destination, timestamp});
        mpp[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
        auto [s, d, t]= q.front();
        q.pop();
        st.erase({s, d, t});
        if(!mpp.empty()) mpp[d].erase(mpp[d].begin());
        return {s, d, t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int cnt=0;
        if(mpp.count(destination)){
            auto& t=mpp[destination];
            auto it1=lower_bound(t.begin(), t.end(), startTime);
            auto it2=upper_bound(t.begin(), t.end(), endTime);
            cnt=distance(it1, it2);
        }
        return cnt;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */