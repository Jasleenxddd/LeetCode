class Solution {
public:
    struct cmp{
        bool operator()(pair<int, double>& a, pair<int, double>& b){
            return a.second< b.second;
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        double maxi=0;
        priority_queue<pair<int, double>, vector<pair<int, double>>, cmp> pq;
        for(int i=0; i<n; i++){
            double passR=classes[i][0]/(double)classes[i][1];
            double change=(classes[i][0]+1)/(double)(classes[i][1]+1);
            pq.push({i, change-passR});
        }
        while(extraStudents>0){
            int i=pq.top().first;
            pq.pop();
            classes[i][0]++;
            classes[i][1]++;
            double passR=classes[i][0]/(double)classes[i][1];
            double change=(classes[i][0]+1)/(double)(classes[i][1]+1);
            pq.push({i, change-passR});
            extraStudents--;
        }
        double ans=0.0;
        for(auto it: classes){
            ans+=it[0]/(double)it[1];
        }
        return ans/n;
    }
};