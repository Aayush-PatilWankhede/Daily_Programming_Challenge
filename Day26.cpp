// Problem : Detect a Cycle in an Undirected Graph
// Solution :

#include<bits/stdc++.h>
using namespace std ;

bool dfs( int node , int parent , vector<bool> &visited , vector<vector<int>> &adj ) {
    visited[node] = true ;

    for( int i = 0 ; i < adj[node].size() ; i++ ) {
        int neighbor = adj[node][i] ;
        if( !visited[neighbor] ) {
            if( dfs( neighbor , node , visited , adj ) ) {
                return true ;
            }
        } else if( neighbor != parent ) {
            return true ;
        }
    }
    return false ;
}

bool isCycle( int V , vector<vector<int>> &edges ) {
    vector<vector<int>> adj( V ) ;
    for( int i = 0 ; i < edges.size() ; i++ ) {
        int u = edges[i][0] ;
        int v = edges[i][1] ;
        adj[u].push_back( v ) ;
        adj[v].push_back( u ) ;
    }

    vector<bool> visited( V , false ) ;

    for( int i = 0 ; i < V ; i++ ) {
        if( !visited[i] ) {
            if( dfs( i , -1 , visited , adj ) ) {
                return true ;
            }
        }
    }
    return false ;
}

int main() {
    int V , E ;
    cin >> V >> E ;

    vector<vector<int>> edges( E , vector<int>(2) ) ;
    for( int i = 0 ; i < E ; i++ ) {
        cin >> edges[i][0] >> edges[i][1] ;
    }

    if( isCycle( V , edges ) ) {
        cout << "true" << endl ;
    } else {
        cout << "false" << endl ;
    }
    return 0 ;
}
