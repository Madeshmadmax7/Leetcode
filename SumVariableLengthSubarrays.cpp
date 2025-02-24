#include<bits/stdc++.h>
using namespace std;
int sumVariableLen(vector<int>arr){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        int start=max(0,i-arr[i]);
        for(int j=start;j<=i;j++){
            sum+=arr[j];
        }
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<sumVariableLen(arr);
}