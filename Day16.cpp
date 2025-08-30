// Problem : LCM (Least Common Multiple) of Two Numbers
// Solution :

#include<bits/stdc++.h>
using namespace std ;

long long findGCD( long long a , long long b ) {
    while( b != 0 ) {
        long long temp = b ;
        b = a % b ;
        a = temp ;
    }
    return a ;
}

long long findLCM( long long a , long long b ) {
    if( a == 0 || b == 0 ) {
        return 0 ;   
    }
    return ( a / findGCD(a , b) ) * b ;
}

int main() {
    long long N , M ;
    cin >> N >> M ;
    cout << findLCM(N , M) << endl ;
    return 0 ;
}
