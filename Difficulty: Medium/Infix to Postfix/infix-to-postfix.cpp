//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int prec(char c) {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return 0;
    }
string infixToPostfix(string &s) {
        stack<char> st;
        string result;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                result += c;
            }
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
            }
            else {
                while (!st.empty() && prec(st.top()) >= prec(c)) {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};


//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends