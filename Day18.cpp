// Problem : Count the Number of Divisors of a Number
// Solution :

#include<bits/stdc++.h>
using namespace std ;

int countDivisors( int n ) {
    int totalDivisors = 0 ;
    for( int i = 1 ; i * i <= n ; i++ ) {
        if( n % i == 0 ) {
            if( i == n / i ) {
                totalDivisors++ ;   
            } else {
                totalDivisors += 2 ;  
            }
        }
    }
    return totalDivisors ;
}

int main() {
    int N ;
    cin >> N ;
    if( N == 0 ) {
        cout << "Undefined" << endl ; 
        return 0 ;
    }
    cout << countDivisors(N) << endl ;
    return 0 ;
}
