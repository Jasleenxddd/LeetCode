class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // parity of the sum should be the same,
        // so there r 2 case either all of them are even or odd
        // or alternate even odd even odd so that parity remains the same
        // we use greedy approach for this
        int n=nums.size();
        int allOdd=0;
        int allEven=0;
        int oddEven=0;
        int evenOdd=0;
        for(auto i: nums){
            if(i%2==0) allEven++;
            else allOdd++;
        }
        int par=0;
        for(auto i: nums){
            if(i%2==par){
                evenOdd++;
                par=!par;
            }
        }
        par=1;
        for(auto i: nums){
            if(i%2==par){
                oddEven++;
                par=!par;
            } 
            
        }
        int ans=max({allOdd, allEven, evenOdd, oddEven});
        return ans;
    }
};