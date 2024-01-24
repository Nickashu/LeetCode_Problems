#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> hashNumbers;
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;

        if(hashNumbers.find(n) != hashNumbers.end())
            return hashNumbers[n];
        int result = climbStairs(n-1) + climbStairs(n-2);
        hashNumbers[n] = result;
        return result;
    }
};