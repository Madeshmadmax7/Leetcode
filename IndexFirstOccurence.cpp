#include<bits/stdc++.h>
using namespace std;
int Occurence(string a,string b){
    if(b.length()>a.length()){
        return -1;
    }
    for(int i=0;i<a.length()-b.length();i++){
        int c=0;
        for(int j=0;j<b.length();j++){
            if(a[i+j]==b[j]){
                c++;
            }
            else{
                break;
            }
        }
        if(c==b.length())
        {
            return i;
        }
    }
}
int main(){
    string a,b;
    cin>>a>>b;
    cout<<Occurence(a,b);
}