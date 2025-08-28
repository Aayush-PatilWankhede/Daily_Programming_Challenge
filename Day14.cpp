// Problem : Count Substrings with Exactly K Distinct Characters
// Solution :

#include<bits/stdc++.h>
using namespace std ;

long long countAtMostK( string &s , int k ) {
    if( k < 0 ) return 0 ;
    int n = s.length() ;
    int left = 0 ;
    long long totalCount = 0 ;
    unordered_map<char , int> frequency ;

    for( int right = 0 ; right < n ; right++ ) {
        frequency[s[right]]++ ;

        while( (int)frequency.size() > k ) {
            frequency[s[left]]-- ;
            if( frequency[s[left]] == 0) {
                frequency.erase(s[left]) ;
            }
            left++ ;
        }

        totalCount += (right - left + 1) ;
    }

    return totalCount ;
}

long long countExactlyK(string &s , int k) {
    if (k <= 0) return 0 ;
    if (k > (int)s.length()) return 0 ;
    return countAtMostK(s , k) - countAtMostK(s , k - 1) ;
}

int main() {
    string s ;
    int k ;
    cin >> s >> k ;
    cout << countExactlyK(s , k) << endl ;
    return 0 ;
}
