#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix="";
        for(int i=0; i<strs[0].size(); i++){
            for(int j=1; j<strs.size(); j++){
                if(i >= strs[j].size())
                    return commonPrefix;

                if(strs[j][i] != strs[0][i])
                    return commonPrefix;
            }
            commonPrefix += strs[0][i];
        }
        return commonPrefix;
    }
};

int main(){
    Solution sol;
    vector<string> strs {"dog","racecar","car"};
    string s = sol.longestCommonPrefix(strs);
    cout << "Prefixo: " << s;
}