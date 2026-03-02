/*
 * @lc app=leetcode id=1935736340 lang=cpp
 *
 * MinStack
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class MinStack {
public:
    int stk[1000000];
    int f,r;
    MinStack() {
        f=-1;
        r=-1;
    }
    
    void push(int val) {
        if(f==-1) f=0;
        stk[++r]=val;
    }
    
    void pop() {
        if(r!=-1){
            r--;
        }
    }
    
    int top() {
        return stk[r];
    }
    
    int getMin() {
        int mini=INT_MAX;
        for(int i=f;i<=r;i++){
            mini=min(mini,stk[i]);
        }
        return mini;
    }
};
