#include<bits/stdc++.h>
using namespace std;
string uniqueBinaryString(vector<string>arr){
    string ans="";
    for(int i=0;i<arr.size();i++){
        ans+=arr[i][i]=='0'?'1':'0';
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<uniqueBinaryString(arr);
}