// Problem : Check if a Binary Tree is a Binary Search Tree (BST)
// Solution :

#include<bits/stdc++.h>
using namespace std ;

struct TreeNode {
    int val ;
    TreeNode *left ;
    TreeNode *right ;
    TreeNode( int x ) : val( x ) , left( nullptr ) , right( nullptr ) {}
} ;

bool isValidBSTHelper( TreeNode* node , long long minVal , long long maxVal ) {
    if( node == nullptr ) {
        return true ;
    }

    if( node->val <= minVal || node->val >= maxVal ) {
        return false ;
    }

    return isValidBSTHelper( node->left , minVal , node->val ) &&
           isValidBSTHelper( node->right , node->val , maxVal ) ;
}

bool isValidBST( TreeNode* root ) {
    return isValidBSTHelper( root , LLONG_MIN , LLONG_MAX ) ;
}

TreeNode* buildTree( vector<string> &nodes ) {
    if( nodes.empty() || nodes[0] == "null" ) {
        return nullptr ;
    }

    TreeNode* root = new TreeNode( stoi( nodes[0] ) ) ;
    queue<TreeNode*> q ;
    q.push( root ) ;

    int i = 1 ;
    while( !q.empty() && i < nodes.size() ) {
        TreeNode* curr = q.front() ;
        q.pop() ;

        if( i < nodes.size() && nodes[i] != "null" ) {
            curr->left = new TreeNode( stoi( nodes[i] ) ) ;
            q.push( curr->left ) ;
        }
        i++ ;

        if( i < nodes.size() && nodes[i] != "null" ) {
            curr->right = new TreeNode( stoi( nodes[i] ) ) ;
            q.push( curr->right ) ;
        }
        i++ ;
    }
    return root ;
}

int main() {
    int n ;
    cin >> n ;
    cin.ignore() ;

    vector<string> nodes( n ) ;
    string line ;
    getline( cin , line ) ;
    stringstream ss( line ) ;
    string node ;
    int idx = 0 ;

    while( getline( ss , node , ',' ) && idx < n ) {
        node.erase( 0 , node.find_first_not_of( " " ) ) ;
        node.erase( node.find_last_not_of( " " ) + 1 ) ;
        nodes[idx++] = node ;
    }

    TreeNode* root = buildTree( nodes ) ;
    if( isValidBST( root ) ) {
        cout << "true" << endl ;
    } else {
        cout << "false" << endl ;
    }
    return 0 ;
}
