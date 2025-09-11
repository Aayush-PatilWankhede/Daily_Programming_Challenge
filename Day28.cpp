// Problem : Check if a Binary Tree is Symmetric
// Solution :

#include<bits/stdc++.h>
using namespace std ;

struct TreeNode {
    int val ;
    TreeNode *left ;
    TreeNode *right ;
    TreeNode( int x ) : val( x ), left( nullptr ), right( nullptr ) {}
} ;

bool isMirror( TreeNode* leftNode, TreeNode* rightNode ) {
    if( leftNode == nullptr && rightNode == nullptr ) {
        return true ;
    }

    if( leftNode == nullptr || rightNode == nullptr ) {
        return false ;
    }

    return ( leftNode->val == rightNode->val ) &&
           isMirror( leftNode->left, rightNode->right ) &&
           isMirror( leftNode->right, rightNode->left ) ;
}

bool isSymmetric( TreeNode* root ) {
    if( root == nullptr ) {
        return true ;
    }
    return isMirror( root->left, root->right ) ;
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
        TreeNode* current = q.front() ;
        q.pop() ;

        if( i < nodes.size() && nodes[i] != "null" ) {
            current->left = new TreeNode( stoi( nodes[i] ) ) ;
            q.push( current->left ) ;
        }
        i++ ;

        if( i < nodes.size() && nodes[i] != "null" ) {
            current->right = new TreeNode( stoi( nodes[i] ) ) ;
            q.push( current->right ) ;
        }
        i++ ;
    }
    return root ;
}

int main() {
    int n ;
    cin >> n ;
    vector<string> nodes( n ) ;
    for( int i = 0 ; i < n ; i++ ) {
        cin >> nodes[i] ;
    }
  
    TreeNode* root = buildTree( nodes ) ;
    if( isSymmetric( root ) ) {
        cout << "true" << endl ;
    } else {
        cout << "false" << endl ;
    }
    return 0 ;
}
