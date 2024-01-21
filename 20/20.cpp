#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stackBrackets;
        bool valid=true;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stackBrackets.push(s[i]);
            else{
                if(!stackBrackets.empty()){
                    switch(s[i]) {
                        case ')':
                            if(stackBrackets.top() == '(')
                                stackBrackets.pop();
                            else
                                valid = false;
                            break;
                        case ']':
                            if(stackBrackets.top() == '[')
                                stackBrackets.pop();
                            else
                                valid = false;
                            break;
                        case '}':
                            if(stackBrackets.top() == '{')
                                stackBrackets.pop();
                            else
                                valid = false;
                            break;
                    }
                    if(!valid)
                        break;
                }
                else{
                    valid = false;
                    break;
                }
            }
        }
        if(!stackBrackets.empty()){
            while(!stackBrackets.empty()){
                stackBrackets.pop();
            }
            valid = false;
        }

        return valid;
    }
};

int main(){
    Solution sol;
    string s = "((([()]{})))";
    bool valid = sol.isValid(s);
    cout << "Valid? " << valid;
}