#include<bits/stdc++.h>
using namespace std;
string lcp(vector<string>arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    string s1=arr[0],s2=arr[n-1];
    string res="";
    for(int i=0;i<s2.size();i++){
        if(s1[i]==s2[i]){
            res+=s1[i];
        }
        else{
            break;
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<lcp(arr);
}