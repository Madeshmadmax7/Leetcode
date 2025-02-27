#include <bits/stdc++.h>
using namespace std;
void moveZeros(vector<int>& arr) {
    int x=0;
    for (int i=0;i<arr.size();i++) {
        if (arr[i] != 0) {
            arr[x++] = arr[i];
        }
    }
    for(int j=x; j<arr.size();j++){
        arr[j]=0;
    }
    for(int num:arr){
        cout<<num<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    moveZeros(arr);
}
