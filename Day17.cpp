// Problem : Prime Factorization of a Number
// Solution :

#include<bits/stdc++.h>
using namespace std ;

vector<long long> primeFactorization( long long n ) {
    vector<long long> factors ;
  
    while( n % 2 == 0 ) {
        factors.push_back(2) ;
        n /= 2 ;
    }

    for( long long i = 3 ; i * i <= n ; i += 2 ) {
        while( n % i == 0 ) {
            factors.push_back(i) ;
            n /= i ;
        }
    }

    if( n > 2 ) {
        factors.push_back(n) ;
    }
    return factors ;
}

int main() {
    long long N ;
    cin >> N ;
    vector<long long> result = primeFactorization(N) ;
    for( long long prime : result ) {
        cout << prime << " " ;
    }
    cout << endl ;
    return 0 ;
}
