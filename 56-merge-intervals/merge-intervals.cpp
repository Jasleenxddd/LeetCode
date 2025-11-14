class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // int n=intervals.size();
        // sort(intervals.begin(),intervals.end());
        // vector<vector<int>> ans;
        // for(int i=0;i<n;i++){
        //     if(ans.empty() || intervals[i][0]>ans.back()[1]){
        //         ans.push_back(intervals[i]);
        //     }
        //     else{
        //         ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        //     }
        // }
        // return ans;
        // int n=intervals.size();
        // int i=0;
        // sort(intervals.begin(),intervals.end());
        // vector<vector<int>> res;
        // while(i<n){

        //     while(i+1<n && intervals[i+1][0]<=intervals[i][1]){
        //     intervals[i][1]=max(intervals[i][1],intervals[i+1][1]);
        //     i++;
        // }
        // res.push_back({intervals[i][0],intervals[i][1]});
        // i++;
        
        // } 
        // return res;
        

        vector<vector<int>> res;
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        int i=0;
        while(i<n){
            int s=intervals[i][0];
            int e=intervals[i][1];
            while(i+1<n && intervals[i+1][0]<=e){
                e=max(intervals[i+1][1], e);
                i++;
            }
            res.push_back({s, e});
            i++;
        } 
        return res;
    }
};