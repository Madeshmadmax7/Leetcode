#include<bits/stdc++.h>
using namespace std;
int sumOfIndex(int num){
    int n=num;
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int smallestIndex(vector<int>& nums){
    for(int i=0;i<nums.size();i++){
        if(i==(sumOfIndex(nums[i]))){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<smallestIndex(nums);
}