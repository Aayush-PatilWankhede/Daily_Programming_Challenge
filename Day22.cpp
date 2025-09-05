// Problem : First Element to Repeat k Times
// Solution :

#include<bits/stdc++.h>
using namespace std ;

int firstElementToRepeatKTimes( vector<int> &arr , int k ) {
    unordered_map<int , int> count ;

    for( int i = 0 ; i < arr.size() ; i++ ) {
        count[arr[i]]++ ;
    }

    for( int i = 0 ; i < arr.size() ; i++ ) {
        if( count[arr[i]] == k ) {
            return arr[i] ;
        }
    }

    return -1 ;
}

int main() {
    int n , k ;
    cin >> n ;

    vector<int> arr(n) ;
    for( int i = 0 ; i < n ; i++ ) {
        cin >> arr[i] ;
    }

    cin >> k ;
    cout << firstElementToRepeatKTimes( arr , k ) << endl ;

    return 0 ;
}
