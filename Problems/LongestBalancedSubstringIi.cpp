/*
 * @lc app=leetcode id=1917983244 lang=cpp
 *
 * LongestBalancedSubstringIi
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int longestBalanced(string s) {
        return max( { one(s),
                      two(s, 'a', 'b'), two(s, 'b', 'c'), two(s, 'a', 'c'),
                      three(s) } );
    }
    
    int one(string& s) {
        int res = 1, n = s.size();
        for (int i = 1, j = 0, cnt = 1; i < n; i++) {
            if (s[i] == s[j])
                res = max(res, ++cnt);
            else {
                j = i;
                cnt = 1;
            }
        }
        return res;
    }
    
    int two(string& s, const char& a, const char& b) {
        int res = 0, n = s.size(), delta = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != a && s[i] != b) {
                mp.clear();
                mp[0] = i;
                delta = 0;
                continue;
            }
            delta += s[i] == a ? 1 : -1;
            if (mp.find(delta) != mp.end())
                res = max(res, i - mp[delta]);
            else
                mp[delta] = i;
        }
        return res;
    }
    
    int three(string& s) {
        int res = 0, n = s.size();
        vector<int> cnts(3, 0); 
        map<vector<int>, int> mp;
        mp[ {0, 0} ] = -1;
        for (int i = 0; i < n; i++) {
            cnts[s[i] - 'a']++;
            vector<int> k = { cnts[1] - cnts[0], cnts[2] - cnts[0] };
            if (mp.find(k) != mp.end())
                res = max(res, i - mp[k]);
            else
                mp[k] = i;
        }
        return res;
    }
};