class Solution {
public:
    bool isPalindrome(string s) {
        string a="";
        for(char c:s){
            if(isalnum(c)){
                a+=tolower(c);
            }
        }
        int n=a.length();
        for(int i=0;i<n/2;i++){
            if(a[i]!=a[n-i-1]){
                return false;
            }
        }
        return true;
    }
};