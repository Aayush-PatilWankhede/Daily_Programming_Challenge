// Problem : Sliding Window Maximum
// Solution :

#include<bits/stdc++.h>
using namespace std ;

vector<int> slidingWindowMaximum( vector<int> &arr , int k ) {
    int n = (int)arr.size() ;
    vector<int> result ;
    if( n == 0 || k <= 0 ) return result ;

    deque<int> dq ; 
    for( int i = 0 ; i < n ; i++ ) {
        while( !dq.empty() && dq.front() <= i - k ) {
            dq.pop_front() ;
        }
        while( !dq.empty() && arr[dq.back()] < arr[i] ) {
            dq.pop_back() ;
        }
        dq.push_back( i ) ;
      
        if( i >= k - 1 ) {
            result.push_back( arr[dq.front()] ) ;
        }
    }
    return result ;
}

int main() {
    int n , k ;
    cin >> n ;
    vector<int> arr(n) ;
    for( int i = 0 ; i < n ; i++ ) {
        cin >> arr[i] ;
    }
    cin >> k ;
    vector<int> ans = slidingWindowMaximum( arr , k ) ;
    for( int i = 0 ; i < ans.size() ; i++ ) {
        cout << ans[i] << " " ;
    }
    cout << endl ;
    return 0 ;
}
