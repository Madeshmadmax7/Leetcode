#include<bits/stdc++.h>
using namespace std;
vector<int>plusOne(vector<int>arr){
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i]<9){
            arr[i]+=1;
            return arr;
        }
        else{
            arr[i]=0;
        }
    }
    arr.insert(arr.begin(),1);
    return arr;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>res=plusOne(arr);
    for(int i:res){
        cout<<i<<" ";
    }
}