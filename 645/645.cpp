#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> setNums;
        int sizeSet=0, num1, num2;
        for(int i=0; i<nums.size(); i++){
            setNums.insert(i+1);
        }
        for(int i=0; i<nums.size(); i++){
            sizeSet = setNums.size();
            setNums.erase(nums[i]);
            if(sizeSet == setNums.size())
                num1 = nums[i];
        }
        num2 = *setNums.begin();

        return {num1, num2};
    }
};