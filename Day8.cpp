// Problem : Reverse a String Word by Word
// Solution :

#include<bits/stdc++.h>
using namespace std ;

string reverseWords(string s) {
    vector<string> words ;
    string word = "" ;

    for( int i = 0 ; i < (int)s.length() ; i++ ) {
        char ch = s[i] ;

        if( ch == '"' ) continue ;  

        if( ch != ' ' ) {
            word += ch ;
        } else {
            if( !word.empty() ) {
                words.push_back(word) ;
                word = "" ;
            }
        }
    }
    if( !word.empty() ) words.push_back(word) ;

    reverse( words.begin(), words.end() ) ;

    string result = "" ;
    for( int i = 0 ; i < (int)words.size() ; i++ ) {
        result += words[i] ;
        if( i != (int)words.size() - 1 ) result += " " ;
    }
    return result ;
}

int main() {
    string s ;
    getline( cin, s ) ;

    string reversedString = reverseWords(s) ;
    cout << reversedString << endl ;

    return 0 ;
}
