class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>lt(n);
        vector<int>rt(n);
        lt[0]=0;
        for(int i=1;i<n;i++){
            lt[i]=lt[i-1]+nums[i-1];
        }
        rt[n-1]=0;
        for(int i=n-2;i>=0;i--){
            rt[i]=rt[i+1]+nums[i+1];
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            res.push_back(abs(lt[i]-rt[i]));
        }
        return res;
    }
};