/*
 * @lc app=leetcode id=1860256092 lang=cpp
 *
 * DeleteColumnsToMakeSorted
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        vector<string>vec(strs[0].length(),"");
        for(auto word:strs){
            for(int i=0;i<word.size();i++){
                vec[i]+=word[i];
            }
        }
        int cnt=0;
        for(auto str:vec){
            string st=str;
            sort(st.begin(),st.end());
            if(str!=st) cnt++;
        }
        return cnt;
    }
};