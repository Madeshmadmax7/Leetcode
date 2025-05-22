#include<bits/stdc++.h>
using namespace std;
void setZero(vector<vector<int>>arr){
    int r=arr.size();
    int c=arr[0].size();
    vector<bool>rv(r,false);
    vector<bool>cv(r,false);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]==0){
                rv[i]=true;
                cv[j]=true;
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(rv[i]||cv[j]){
                arr[i][j]=0;
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    setZero(arr);
}