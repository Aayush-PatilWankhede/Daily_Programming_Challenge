// Problem : Longest Palindromic Substring
// Solution :

#include<bits/stdc++.h>
using namespace std ;

pair<int,int> expandFromCenter( const string &s , int left , int right ) {
    int n = (int)s.length() ;
    while( left >= 0 && right < n && s[left] == s[right] ) {
        left-- ;
        right++ ;
    }
    return make_pair( left + 1 , right - 1 ) ;
}

string longestPalindromicSubstring( string s ) {
    int n = (int)s.length() ;
    if( n == 0 ) return "" ;

    int startIndex = 0 ;
    int maxLength = 1 ;

    for( int center = 0 ; center < n ; center++ ) {
        pair<int,int> p1 = expandFromCenter( s , center , center ) ;
        int len1 = p1.second - p1.first + 1 ;
        if( len1 > maxLength ) {
            startIndex = p1.first ;
            maxLength = len1 ;
        }

        pair<int,int> p2 = expandFromCenter( s , center , center + 1 ) ;
        int len2 = p2.second - p2.first + 1 ;
        if( len2 > maxLength ) {
            startIndex = p2.first ;
            maxLength = len2 ;
        }
    }

    return s.substr( startIndex , maxLength ) ;
}

int main() {
    string input ;
    cin >> input ;
    cout << longestPalindromicSubstring( input ) << endl ;
    return 0 ;
}
