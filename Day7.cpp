// Problem : Trapping Rain Water
// Solution :

#include<bits/stdc++.h>
using namespace std ;

int trapRainWater( vector<int>& height, int n ) {
    int left = 0, right = n - 1 ;
    int maxLeft = 0, maxRight = 0 ;
    int water = 0 ;

    while( left <= right ) {
        if( height[left] <= height[right] ) {
            if( height[left] >= maxLeft ) {
                maxLeft = height[left] ;
            } else {
                water += maxLeft - height[left] ;
            }
            left++ ;
        } else {
            if( height[right] >= maxRight ) {
                maxRight = height[right] ;
            } else {
                water += maxRight - height[right] ;
            }
            right-- ;
        }
    }
    return water ;
}

int main() {
    int n ;
    cin >> n ;

    vector<int> height(n) ;
    for( int i = 0 ; i < n ; i++ ) {
        cin >> height[i] ;
    }

    int totalWater = trapRainWater(height, n) ;
    cout << totalWater << endl ;

    return 0 ;
}
