/*
 * @lc app=leetcode id=1985015104 lang=cpp
 *
 * WordsWithinTwoEditsOfDictionary
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool compare(string word,string org){
        int sum=0;
        for(int i=0;i<word.length();i++){
            if(word[i]!=org[i]){
                sum++;
            }
        }
        if(sum<=2){
            return true;
        }
        return false;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size();
        int m=dictionary.size();
        vector<string>res;
        for(int j=0;j<n;j++){
            string comp=queries[j];
            for(int i=0;i<m;i++){
                string word=dictionary[i];
                bool is2=compare(word,comp);
                if(is2){
                    res.push_back(comp);
                    break;
                }
            }
        }
        return res;
    }
};