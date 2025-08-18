// Problem : Merge Two Sorted Arrays
// solution :

#include <bits/stdc++.h>
using namespace std ;

void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int i, int j) {
    if( arr1[i] > arr2[j] ) {
        swap(arr1[i], arr2[j]) ;
    }
}

void mergeArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int len = m + n ;
    int gap = (len / 2) + (len % 2) ;

    while( gap > 0 ) {
        int left = 0 ;
        int right = left + gap ;

        while( right < len ) {
            if( left < m && right < m ) {
                swapIfGreater(arr1, arr1, left, right) ;
            }
            else if( left < m && right >= m ) {
                swapIfGreater(arr1, arr2, left, right - m) ;
            }
            else {
                swapIfGreater(arr2, arr2, left - m, right - m) ;
            }
            left++ ;
            right++ ;
        }

        if( gap == 1 ) gap = 0 ;
        else gap = (gap / 2) + (gap % 2) ;
    }
}

int main() {
    int m, n ;
    cin >> m >> n ;

    vector<int> arr1(m), arr2(n) ;
    for( int i = 0 ; i < m ; i++ ) cin >> arr1[i] ;
    for( int j = 0 ; j < n ; j++ ) cin >> arr2[j] ;

    mergeArrays(arr1, arr2, m, n) ;

    for( int i = 0 ; i < m ; i++ ) cout << arr1[i] << " " ;
    for( int j = 0 ; j < n ; j++ ) cout << arr2[j] << " " ;
    cout << endl ;

    return 0 ;
}
