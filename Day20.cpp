// Problem : Sort a Stack Using Recursion
// Solution :

#include<bits/stdc++.h>
using namespace std ;

void insertSorted( stack<int> &st , int element ) {
    if( st.empty() || st.top() <= element ) {
        st.push( element ) ;
        return ;
    }

    int temp = st.top() ; 
    st.pop() ;
    insertSorted( st , element ) ;
    st.push( temp ) ;
}

void sortStack( stack<int> &st ) {
    if( st.empty() ) {
        return ;
    }

    int topElement = st.top() ;
    st.pop() ;
    sortStack( st ) ;
    insertSorted( st , topElement ) ;
}

int main() {
    stack<int> st ;
    int x ;

    while( cin >> x ) {
        st.push( x ) ;
    }

    sortStack( st ) ;

    vector<int> result ;
    while( !st.empty() ) {
        result.push_back( st.top() ) ;
        st.pop() ;
    }

    reverse( result.begin() , result.end() ) ;
    for( int val : result ) {
        cout << val << " " ;
    }
    cout << endl ;

    return 0 ;
}
