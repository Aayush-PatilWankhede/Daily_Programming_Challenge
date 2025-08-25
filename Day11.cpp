// Problem : Permutations of a String
// Solution :

#include<bits/stdc++.h>
using namespace std ;

void generatePermutations( string &s , int index , vector<string> &result ) {
    if( index == s.length() ) {
        result.push_back(s) ;
        return ;
    }

    unordered_set<char> used ;
    for( int i = index ; i < s.length() ; i++ ) {
        if( used.find(s[i]) != used.end() ) {
            continue ; 
        }
        used.insert(s[i]) ;

        swap( s[index], s[i] ) ;
        generatePermutations( s , index + 1 , result ) ;
        swap( s[index], s[i] ) ; 
    }
}

vector<string> getAllPermutations( string s ) {
    vector<string> result ;
    generatePermutations( s , 0 , result ) ;
    return result ;
}

int main() {
    string s ;
    cin >> s ;

    vector<string> permutations = getAllPermutations(s) ;
    sort( permutations.begin(), permutations.end() );
    
    for( int i = 0 ; i < permutations.size() ; i++ ) {
        cout << permutations[i] << " " ;
    }
    cout << endl ;
    return 0 ;
}
