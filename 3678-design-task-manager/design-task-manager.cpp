class TaskManager {
public:
    // taskID, unserID, priority
    unordered_map<int, pair<int, int>> mpp;
    // priority, taskId
    priority_queue<pair<int, int>> st;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& task: tasks){
            int t=task[1];
            int user=task[0];
            int p=task[2];
            mpp[t]={user, p};
            st.push({p, t});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mpp[taskId]={userId, priority};
        st.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int user=mpp[taskId].first;
        mpp[taskId]={user, newPriority};
        st.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        mpp.erase(taskId);
    }
    
    int execTop() {
        while(!st.empty()){
            auto [p, t]=st.top();
            if(mpp.count(t) && mpp[t].second == p){
                int user=mpp[t].first;
                mpp.erase(t);
                st.pop();
                return user;
            }
            st.pop();
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */