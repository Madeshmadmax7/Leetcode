/*
 * @lc app=leetcode id=1892698744 lang=cpp
 *
 * SpecialArrayI
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool isArraySpecial(vector<int>& arr) {
        bool flag=true;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]%2==0&&arr[i+1]%2!=1){
                flag=false;
                return flag;
            }
            else if(arr[i]%2!=0&&arr[i+1]%2==1){
                flag=false;
                return flag;
            }
        }
        return flag;
    }
};