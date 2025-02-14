#include<bits/stdc++.h>
using namespace std;
bool isValid(string a){
    int n=a.length();
    vector<char> arr(a.begin(),a.end());
    stack<char> stk;
    for(char a:arr){
        if(a=='('||a=='['||a=='{'){
            stk.push(a);
        }
        else{
            if(stk.empty()){
                return false;
            }
            if(
                (a==')'&&stk.top()=='(')||
                (a==']'&&stk.top()=='[')||
                (a=='}'&&stk.top()=='{')
            ){
                stk.pop();
            }
            else{
                return false;
            }
        }
    }
    return stk.empty();
}
int main(){
    string a;
    cin>>a;
    if(isValid(a)){
        cout<<"Valid";
    }
    else{
        cout<<"Invalid";
    }
}