#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


//ITERATIVE TRAVERSAL

//BFS----------
//PREORDER 

vector<int> preorder(struct Node*root){
    vector<int>ans;
    if(root==NULL) return ans;

    stack <Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* root=st.top();
        st.pop();
        ans.push_back(root->data);
        if(root->right!=NULL) st.push(root->right);
        if(root->left!=NULL) st.push(root->left);
    }

    return ans;
}

//postorder 



int main(){

    return 0;
}