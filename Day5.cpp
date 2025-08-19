// Problem : Find the Leaders in an Array
// Solution :

#include<bits/stdc++.h>
using namespace std ;

vector<int> findLeaders( vector<int>& elements, int n ) {
    vector<int> ans ;
    int maxi = elements[n-1] ;
    ans.push_back(maxi) ;

    for( int i = n-2 ; i >= 0 ; i-- ) {
        if( elements[i] > maxi ) {   
            ans.push_back(elements[i]) ;
            maxi = elements[i] ;
        }
    }

    reverse( ans.begin(), ans.end() ) ;
    return ans ;
}

int main() {
    int n ;
    cin >> n ;
    vector<int> elements(n) ;
    for( int i = 0; i < n; i++ ) cin >> elements[i] ;

    vector<int> leaders = findLeaders(elements, n) ;

    for( int x : leaders ) cout << x << " " ;
    cout << endl ;

    return 0 ;
}
