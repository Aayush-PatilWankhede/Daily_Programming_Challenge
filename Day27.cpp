// Problem : Find the Shortest Path in an Unweighted Graph
// Solution :

#include<bits/stdc++.h>
using namespace std ;

int shortestPath( int V , vector<vector<int>> &edges , int start , int end ) {
    vector<vector<int>> adj( V ) ;
    
    for( int i = 0 ; i < edges.size() ; i++ ) {
        int u = edges[i][0] ;
        int v = edges[i][1] ;
        adj[u].push_back( v ) ;
        adj[v].push_back( u ) ;
    }

    vector<bool> visited( V , false ) ;
    queue<pair<int, int>> q ; 
    
    q.push( { start , 0 } ) ;
    visited[start] = true ;

    while( !q.empty() ) {
        pair<int, int> front = q.front() ;
        q.pop() ;
        
        int node = front.first ;
        int dist = front.second ;
        
        if( node == end ) {
            return dist ;
        }
        
        for( int i = 0 ; i < adj[node].size() ; i++ ) {
            int neighbor = adj[node][i] ;
            if( !visited[neighbor] ) {
                visited[neighbor] = true ;
                q.push( { neighbor , dist + 1 } ) ;
            }
        }
    }
    return -1 ; 
}

int main() {
    int V , E ;
    cin >> V >> E ;
    vector<vector<int>> edges( E , vector<int>(2) ) ;
    for( int i = 0 ; i < E ; i++ ) {
        cin >> edges[i][0] >> edges[i][1] ;
    }

    int start , end ;
    cin >> start >> end ;
    cout << shortestPath( V , edges , start , end ) << endl ;
    return 0 ;
}
