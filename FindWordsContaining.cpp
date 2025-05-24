#include<bits/stdc++.h>
using namespace std;
vector<int>findWords(vector<string>&arr,char c){
    vector<int>res;
    for(int i=0;i<arr.size();i++){
        string w=arr[i];
        for(char ch:w){
            if(ch==c){
                res.push_back(i);
                break;
            }
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    char x;
    cin>>x;
    vector<int>res=findWords(arr,x);
    cout<<"[";
    for(int i=0;i<n;i++){
        if(i==n-1){
            cout<<res[i];
        }
        else{
            cout<<res[i]<<", ";
        }
    }
    cout<<"]";
}