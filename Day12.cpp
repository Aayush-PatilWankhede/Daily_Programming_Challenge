// Problem : Valid Parentheses with Multiple Types
// Solution :

#include<bits/stdc++.h>
using namespace std;

bool isValid( string s ) {
    stack<char> st ;

    unordered_map<char, char> bracketMap = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for( char ch : s ) {
        if( ch == '(' || ch == '[' || ch == '{' ) {
            st.push(ch) ;
        }
        else {
            if( st.empty() || st.top() != bracketMap[ch] ) {
                return false ;
            }
            st.pop() ;
        }
    }

    // If stack is empty, all brackets matched
    return st.empty() ;
}

int main() {
    string s ;
    cin >> s ;

    bool result = isValid(s);
    cout << ( result ? "true" : "false" ) << endl ;

    return 0 ;
}
