#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Node{
    int data;
    struct Node*left;
    struct Node*right;

    Node(int val){
        data =val;
        left=NULL;
        right=left;
    }
};

//Breadth First Search

void preorder(struct Node * node){
    //Root Left Right
    if(node==NULL) return;

    cout<<node->data<<' ';
    preorder(node->left);
    preorder(node->right);
}

void inorder(struct Node * node){
    //Root Left Right
    if(node==NULL) return;

    preorder(node->left);
    cout<<node->data<<' ';
    preorder(node->right);
}

void postorder(struct Node * node){
    //Root Left Right
    if(node==NULL) return;

    preorder(node->left);
    preorder(node->right);
    cout<<node->data<<' ';
}

//Depth First Search

vector<vector<int>> dfs(struct Node * node){
    vector<vector<int>> ans;
    if (node==NULL) return ans;

    queue<Node*> q;
    q.push(node);

    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            Node*root=q.front();
            q.pop();
            if(root->left!=NULL) q.push(root->left);
            if(root->right!=NULL) q.push(root->right);
            level.push_back(root->data);
        }
        ans.push_back(level);
    }

    return ans;

}



int main(){

    

    return 0;
}