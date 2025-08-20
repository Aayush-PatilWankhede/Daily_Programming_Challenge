// Problem : Find All Subarrays with Zero Sum
// Solution :

#include<bits/stdc++.h>
using namespace std ;

vector<pair<int, int>> findZeroSumSubarrays( vector<int>& arr, int n ) {
    vector<pair<int, int>> result ;
    unordered_map<long long, vector<int>> prefixSumMap ; 
    long long sum = 0 ;

    for( int i = 0 ; i < n ; i++ ) {
        sum += arr[i] ;
      
        if( sum == 0 ) {
            result.push_back(make_pair(0, i)) ;
        }

        if( prefixSumMap.find(sum) != prefixSumMap.end() ) {
            vector<int> indices = prefixSumMap[sum] ;
            for (int j = 0 ; j < indices.size() ; j++) {
                result.push_back(make_pair(indices[j] + 1, i)) ;
            }
        }

        prefixSumMap[sum].push_back(i) ;
    }

    return result ;
}

int main() {
    int n ;
    cin >> n ;
    vector<int> arr(n) ;
    for( int i = 0 ; i < n ; i++ ) {
        cin >> arr[i] ;
    }

    vector<pair<int,int>> subarrays = findZeroSumSubarrays(arr, n) ;

    for( int i = 0 ; i < subarrays.size() ; i++ ) {
        cout << "(" << subarrays[i].first << ", " << subarrays[i].second << ") " ;
    }
    cout << endl ;

    return 0 ;
}
