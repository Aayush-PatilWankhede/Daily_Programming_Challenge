// Problem : Find the Longest Substring Without Repeating Characters
// Solution :

#include<bits/stdc++.h>
using namespace std ;

int longestSubstringWithoutRepeatingCharacters( string s ) {
    int n = s.length() ;
    int left = 0 ;
    int maxLength = 0 ;
    unordered_map<char , int> lastSeen ;

    for( int right = 0 ; right < n ; right++ ) {
        char currentCharacter = s[right] ;

        if( lastSeen.find(currentCharacter) != lastSeen.end() && lastSeen[currentCharacter] >= left ) {
            left = lastSeen[currentCharacter] + 1 ;
        }

        lastSeen[currentCharacter] = right ;
        maxLength = max(maxLength , right - left + 1) ;
    }

    return maxLength ;
}

int main() {
  
    string s ;
    cin >> s ;
    cout << longestSubstringWithoutRepeatingCharacters(s) << endl ;
    return 0 ;
  
}
