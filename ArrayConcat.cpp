#include<bits/stdc++.h>
using namespace std;
vector<int> arrayConcat(vector<int>arr){
    vector<int>res;
    for(int i=0;i<arr.size();i++){
        res.push_back(arr[i]);
    }
    for(int i=0;i<arr.size();i++){
        res.push_back(arr[i]);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> res = arrayConcat(arr);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
}