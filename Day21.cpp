// Problem : Reverse a Stack Using Recursion
// Solution :

#include<bits/stdc++.h>
using namespace std ;

void insertAtBottom( stack<int> &st , int element ) {
    if( st.empty() ) {
        st.push( element ) ;
        return ;
    }
    int topElement = st.top() ;
    st.pop() ;
    insertAtBottom( st , element ) ;
    st.push( topElement ) ;
}

void reverseStack( stack<int> &st ) {
    if( st.empty() ) {
        return ;
    }
    int topElement = st.top() ;
    st.pop() ;
    reverseStack( st ) ;
    insertAtBottom( st , topElement ) ;
}

void printStack( stack<int> st ) {
    vector<int> arr ;
    while( !st.empty() ) {
        arr.push_back( st.top() ) ;
        st.pop() ;
    }
    for( int i = arr.size() - 1 ; i >= 0 ; i-- ) {
        cout << arr[i] << " " ;
    }
}

int main() {
    stack<int> st ;
    int x ;

    while( cin >> x ) {
        st.push( x ) ;
    }

    reverseStack( st ) ;

    printStack( st ) ;
    cout << endl ;

    return 0 ;
}

