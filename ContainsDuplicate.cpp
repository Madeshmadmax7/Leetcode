#include<bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int>arr){
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]==arr[i+1]){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<containsDuplicate(arr);
}