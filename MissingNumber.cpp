#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>arr){
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=i){
            return i;
        }
    }
    return arr.size();
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<missingNumber(arr);
}