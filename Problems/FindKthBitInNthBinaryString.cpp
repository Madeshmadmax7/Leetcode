/*
 * @lc app=leetcode id=1936821080 lang=cpp
 *
 * FindKthBitInNthBinaryString
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    string inv(string &s){

        string res = "" ; 

        for(auto &it : s){
            if(it == '0'){
                res += '1' ; 
            }else{
                res += '0' ; 
            }
        }

        return res ; 
    }
    char findKthBit(int n, int k) {

        if(n == 1 && k == 1){
            return '0';
        }

        string s = "0"; 
        string ans = "" ; 

        for(int i = 1 ; i < n ; i++){

            string b = inv(s); 
           reverse(b.begin() , b.end());
            
            ans = s + "1" + b ; 
            s = ans ; 

        }

        return ans[k-1]; 
        
    }
};