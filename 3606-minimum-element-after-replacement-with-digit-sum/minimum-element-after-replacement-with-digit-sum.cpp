class Solution {
public:
    int findsum(int num){
        int temp=0;
        while(num>0){
            temp+=num%10;
            num/=10;
        }
        return temp;
    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=findsum(nums[i]);
            mini=min(mini,sum);
        }
        return mini;
    }

};