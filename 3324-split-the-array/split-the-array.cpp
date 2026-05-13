class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int n:nums){
            mp[n]++;
            if(mp[n]>2){
                mp[n]++;
                return false;
            }
        }
        return true;
    }
};