/*
 * @lc app=leetcode id=1948926710 lang=cpp
 *
 * FancySequence
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

#define ll long long
class Fancy {
    int global_mul, global_inc;
    vector<int> vec;
    int md = 1e9+7;
public:
    Fancy() {
        global_mul=1; global_inc = 0;
    }
    int binpow(int a,int e){
        int res = 1;
        while(e>0){
            if(e&1){
                res = ((ll)res*a)%md;
            }
            a = ((ll)a*a)%md;
            e >>= 1;
        }
        return res;
    }
    int mdinv(int b){
        return binpow(b,md-2);
    }
    int divmod(int a,int b){
        return ((ll)(a%md)*(mdinv(b)%md))%md;
    }
    void append(int val) {
        val = ((ll)val - global_inc + md)%md;
        val = divmod(val,global_mul);
        vec.push_back(val);
    }
    
    void addAll(int inc) {
        global_inc = ((ll)global_inc + inc)%md;
    }
    
    void multAll(int m) {
        global_mul = ((ll)global_mul * m)%md;
        global_inc = ((ll)global_inc * m)%md;
    }
    
    int getIndex(int idx) {
        if(idx >= vec.size()) return -1;
        int ans = vec[idx];
        ans = ((ll)ans*global_mul)%md;
        ans = ((ll)ans + global_inc)%md;
        return ans;
    }
};
