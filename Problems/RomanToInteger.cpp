/*
 * @lc app=leetcode id=1937874978 lang=cpp
 *
 * RomanToInteger
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
       int total=0, prev=0;
       for(int i=s.size()-1;i>=0;--i){
            int curr=0;
            char ch=toupper(s[i]);
            switch(ch){
                case 'I': curr=1; break;
                case 'V': curr=5; break;
                case 'X': curr=10; break;
                case 'L': curr=50; break;
                case 'C': curr=100; break;
                case 'D': curr=500; break;
                case 'M': curr=1000; break;
            default: curr=0; break;
            }
            if(curr<prev) total -= curr;
            else{ total += curr; prev=curr;}
       } 
       return total;
    }
};