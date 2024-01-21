#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    int romanToInt(string s) {
        int num=0;
        for(int i=0; i<s.size(); i++){
            if(prefixSub(s, i))
                num -= roman[s[i]];
            else
                num += roman[s[i]];
        }

        return num;
    }

    bool prefixSub(string s, int i){
        if(i < s.size()-1){
            if(roman[s[i]] < roman[s[i+1]])
                return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    int num = sol.romanToInt("XIX");
    cout << "Numero: " << num;
}