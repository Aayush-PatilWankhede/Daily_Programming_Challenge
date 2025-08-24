// Problem : Group Anagrams
// Solution :

#include<bits/stdc++.h>
using namespace std ;

vector<vector<string>> groupAnagrams( vector<string>& strs ) {
    unordered_map<string, vector<string>> anagramMap ;
    
    for( int i = 0 ; i < strs.size() ; i++ ) {
        string sortedStr = strs[i] ;
        sort( sortedStr.begin(), sortedStr.end() ) ; 
        anagramMap[sortedStr].push_back(strs[i]) ; 
    }
    
    vector<vector<string>> result ;
    for( auto& entry : anagramMap ) {
        result.push_back(entry.second) ;
    }
    return result ;
}

int main() {
    int n ;
    cin >> n ;
    vector<string> strs(n) ;
    
    for( int i = 0 ; i < n ; i++ ) {
        cin >> strs[i] ;
    }
    
    vector<vector<string>> groups = groupAnagrams(strs) ;
    
    for( int i = 0 ; i < groups.size() ; i++ ) {
        cout << "[ " ;
        for( int j = 0 ; j < groups[i].size() ; j++ ) {
            cout << groups[i][j] ;
            if( j < groups[i].size() - 1 ) cout << ", " ;
        }
        cout << " ]" << endl ;
    }
    
    return 0 ;
}
