#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0; i<numRows; i++){
            int sizeCurrentArray = i+1;
            vector<int> currentArray;
            for(int j=0; j<sizeCurrentArray; j++){
                if(j == 0 || j == i)
                    currentArray.push_back(1);
                else
                    currentArray.push_back(result[i-1][j-1] + result[i-1][j]);
            }

            result.push_back(currentArray);
        }

        return result;
    }
};