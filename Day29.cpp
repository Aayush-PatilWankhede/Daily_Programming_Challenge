// Problem : Fibonacci Sequence using Dynamic Programming
// Solution :

#include<bits/stdc++.h>
using namespace std ;

string addStrings( string num1 , string num2 ) {
    string result = "" ;
    int carry = 0 ;
    int i = num1.length() - 1 ;
    int j = num2.length() - 1 ;

    while( i >= 0 || j >= 0 || carry > 0 ) {
        int digit1 = ( i >= 0 ) ? num1[i] - '0' : 0 ;
        int digit2 = ( j >= 0 ) ? num2[j] - '0' : 0 ;
        int sum = digit1 + digit2 + carry ;
        result = char( sum % 10 + '0' ) + result ;
        carry = sum / 10 ;
        i-- ;
        j-- ;
    }
    return result ;
}

string fibonacciSequence( int n ) {
    if( n == 0 ) {
        return "0" ;
    }
    if( n == 1 ) {
        return "1" ;
    }

    string prev2 = "0" ;
    string prev1 = "1" ;
    string current ;

    for( int i = 2 ; i <= n ; i++ ) {
        current = addStrings( prev1 , prev2 ) ;
        prev2 = prev1 ;
        prev1 = current ;
    }
    return current ;
}

int main() {
    int n ;
    cin >> n ;
    string result = fibonacciSequence( n ) ;
    cout << result << endl ;
    return 0 ;
}
