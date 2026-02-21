/*
 * @lc app=leetcode id=1926439727 lang=cpp
 *
 * PrimeNumberOfSetBitsInBinaryRepresentation
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int bit = 0;
        
        while (left <= right) {
            int temp = left;
            int cont = 0;

            while (temp > 0) {
                int binary = temp % 2;
                temp = temp / 2;
                if (binary == 1) {
                    cont++;
                }
            }

            if (isPrime(cont)) {
                bit++;
            }

            left++;
            
        };

        return bit;
    }
};