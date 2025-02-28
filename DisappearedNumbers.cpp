#include<bits/stdc++.h>
using namespace std;
void disappearedNumbers(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        int ind=abs(arr[i])-1;
        if(arr[ind]>0){
            arr[ind]=-arr[ind];
        }
    }
    vector<int>res;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            res.push_back(i+1);
        }
    }
    for(int num:res){
        cout<<num<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    disappearedNumbers(arr);
}