#include<bits/stdc++.h>
using namespace std;
bool conseq(vector<int>arr){
    bool found=false;
    if(arr.size()<3){
        return false;
    }
    for(int i=0;i<=arr.size()-3;i++){
        if(arr[i]%2!=0 && arr[i+1]%2!=0 && arr[i+2]%2!=0){
            found=true;
            break;
        }
        else{
            found=false;
        }
    }
    return found;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<conseq(arr);
}