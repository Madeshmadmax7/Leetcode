#include<bits/stdc++.h>
using namespace std;
int moreWaterContainer(vector<int>arr){
    int n=arr.size();
    int water=0;
    int h=0;
    int i=0,j=n-1;
    while(i<j){
        int h=min(arr[i],arr[j]);
        water=max(water,(j-i)*h);
        if(arr[i]<arr[j]){
            i++;
        }
        else{
            j--;
        }
    }
    return water;
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
    cout<<moreWaterContainer(arr);
}