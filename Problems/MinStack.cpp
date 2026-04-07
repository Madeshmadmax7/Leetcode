/*
 * @lc app=leetcode id=1971757715 lang=cpp
 *
 * MinStack
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class MinStack {
public:
    stack<pair<int,int>>stk;
    MinStack() {
    
    }
    
    void push(int val) {
        int mini=stk.empty()?val:min(val,stk.top().second);
        stk.push({val,mini});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        int res=stk.top().second;
        return res;
    }
};