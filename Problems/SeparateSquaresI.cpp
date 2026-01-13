/*
 * @lc app=leetcode id=1883921399 lang=cpp
 *
 * SeparateSquaresI
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    double separateSquares(vector<vector<int>>& sq) {
        double total=0,low=2e9,high=0;
        int i;
        for(i=0;i<sq.size();i++){
            double y,l;
            y=sq[i][1];
            l=sq[i][2];;
            total+=l*l;
            low = min(low,y);
            high = max(high,y+l);
        }
        double half = total/2.0;
        for(i=0;i<48;i++){
            double mid = low +(high-low)/2.0;
            double nw=0;
            for(int j=0;j<sq.size();j++){
                double y,l;
                y=sq[j][1];
                l=sq[j][2];
                if(mid>=l+y) nw+=l*l;
                else if(mid<=y) nw+=0;
                else nw+= l*(mid-y); 
            }
            if(nw<half)
               low = mid;
            else high = mid; 
        }
        return high;
    }
};
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();