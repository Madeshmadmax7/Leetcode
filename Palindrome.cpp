#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int rev=0;
    int temp=n;
    while(n!=0){
        rev=rev*10+n%10;
        n=n/10;
    }
    if(temp==rev){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not a Palindrome";
    }
}