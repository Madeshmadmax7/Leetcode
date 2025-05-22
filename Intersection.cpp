#include<bits/stdc++.h>
using namespace std;
void intersection(vector<int>arr1,vector<int>arr2){
    vector<int>res;
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr2.size();j++){
            if(arr1[i]==arr2[j]){
                bool isVisited=false;
                for(int k=0;k<res.size();k++){
                    if(res[k]==arr1[i]){
                        isVisited=true;
                        break;
                    }
                }
                if(!isVisited){
                    res.push_back(arr1[i]);
                }
            }
        }
    }

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}
int main(){
    int n1,n2;
    cin>>n1>>n2;
    vector<int>arr1;
    vector<int>arr2;
    for(int i=0;i<n1;i++){
        int val;
        cin>>val;
        arr1.push_back(val);
    }
    for(int i=0;i<n2;i++){
        int val;
        cin>>val;
        arr2.push_back(val);
    }
    intersection(arr1,arr2);
}