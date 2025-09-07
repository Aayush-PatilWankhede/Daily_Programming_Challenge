// Problem : Lowest Common Ancestor (LCA) in a Binary Tree
// Solution :

#include<bits/stdc++.h>
using namespace std ;

struct TreeNode {
    int val ;
    TreeNode *left ;
    TreeNode *right ;
    TreeNode( int x ) : val( x ) , left( nullptr ) , right( nullptr ) {}
} ;

TreeNode* lowestCommonAncestor( TreeNode* root , TreeNode* p , TreeNode* q ) {
    if( root == nullptr ) {
        return nullptr ;
    }

    if( root == p || root == q ) {
        return root ;
    }

    TreeNode* leftLCA = lowestCommonAncestor( root->left , p , q ) ;
    TreeNode* rightLCA = lowestCommonAncestor( root->right , p , q ) ;

    if( leftLCA != nullptr && rightLCA != nullptr ) {
        return root ;
    }
    return ( leftLCA != nullptr ) ? leftLCA : rightLCA ;
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

TreeNode* findNode( TreeNode* root , int val ) {
    if( root == nullptr ) {
        return nullptr ;
    }

    if( root->val == val ) {
        return root ;
    }

    TreeNode* left = findNode( root->left , val ) ;
    if( left != nullptr ) {
        return left ;
    }
    return findNode( root->right , val ) ;
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

    int pVal , qVal ;
    cin >> pVal >> qVal ;
    TreeNode* root = buildTree( nodes ) ;
    TreeNode* p = findNode( root , pVal ) ;
    TreeNode* q = findNode( root , qVal ) ;
    TreeNode* lca = lowestCommonAncestor( root , p , q ) ;
    cout << lca->val << endl ;
    return 0 ;
}
