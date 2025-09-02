// Problem : Evaluate a Postfix Expression
// Solution :

#include<bits/stdc++.h>
using namespace std ;

int power( int base , int exp ) {
    int result = 1 ;
    while( exp-- > 0 ) {
        result *= base ;
    }
    return result ;
}

int evaluatePostfix( string expression ) {
    stack<int> st ;
    stringstream ss( expression ) ;
    string token ;

    while( ss >> token ) {
        
        if( token == "+" || token == "-" || token == "*" || token == "/" || token == "^" ) {
            int operand2 = st.top() ; st.pop() ;
            int operand1 = st.top() ; st.pop() ;
            int result = 0 ;

            if( token == "+" ) {
                result = operand1 + operand2 ;
            } else if( token == "-" ) {
                result = operand1 - operand2 ;
            } else if( token == "*" ) {
                result = operand1 * operand2 ;
            } else if( token == "/" ) {
                
                if( operand2 == 0 ) {
                    throw runtime_error( "Division by zero" ) ;
                }
                result = operand1 / operand2 ;
            } else if( token == "^" ) {
                result = power( operand1 , operand2 ) ;
            }

            st.push( result ) ;
        }
  
        else {
            st.push( stoi( token ) ) ;
        }
    }

    return st.top() ;
}

int main() {
    string expression ;
    getline( cin , expression ) ;
    cout << evaluatePostfix( expression ) << endl ;
    return 0 ;
}
