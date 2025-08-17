// Problem : Find the Duplicate Number
// solution :

#include <bits/stdc++.h>
using namespace std ;

int findDuplicate(vector<int>& arr, int n) {
    int slow = arr[0], fast = arr[0] ;

    do {
        slow = arr[slow] ;
        fast = arr[arr[fast]] ;
    } while( slow != fast ) ;

    fast = arr[0] ;
    while( slow != fast ) {
        slow = arr[slow] ;
        fast = arr[fast] ;
    }
    return slow ;
}

int main() {
    int n ;
    cin >> n ;
    vector<int> arr(n+1) ;
    for( int i = 0 ; i <= n ; i++ ) {
        cin >> arr[i] ;
    }

    cout << findDuplicate(arr, n) << endl ;
    return 0 ;
}
