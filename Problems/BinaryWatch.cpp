/*
 * @lc app=leetcode id=1922276343 lang=cpp
 *
 * BinaryWatch
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
    void add_one(vector<string> &ans, int time, int start, int left)
    {
        if(left == 0)
        {
            int hour = time>>6;
            int minute = time & 0x3F;
            string h;
            if(hour > 11 || minute> 59) return;
            if (hour/10) h = ('0'+hour/10);
            string t = h +(char) ('0'+hour%10)+':'+(char)('0'+minute/10)+(char)('0'+minute%10);
            ans.push_back(t);
            return;
        }
        for(int i=start; i<=10-left; i++)
        {
            add_one(ans, time+(1<<i),i+1,left-1);
        }
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        if (turnedOn == 0) return {"0:00"};
        int time = 0;
        vector<string> ans;
        add_one(ans, time,0,turnedOn);
        return ans;

        
    }
};