#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

struct Node { 
    int data; 
    Node *left, *right; 
}; 
  
// Function to create new node 
Node* newNode(int data)   //new concept must learn
{ 
    Node* temp = new Node(); 
    temp->data = data; 
    temp->left = temp->right = nullptr; 
    return temp; 
} 

//time complexity O(n+k) n->total no. of nodes in the BST
void Find(Node *root,int k){
    queue<Node*> Q;
    cout << "Tree : ";
    priority_queue<int,std::vector<int>,std::greater<int>> nodes;
    Q.push(root);
    Node* temp;
    while(!Q.empty()){
        temp=Q.front();
        cout << temp->data << " ";
        Q.pop();
        if(temp->left!=nullptr)Q.push(temp->left);
        if(temp->right!=nullptr)Q.push(temp->right);
        if(temp->left==nullptr && temp->right==nullptr)nodes.push(temp->data);
    }
    cout << endl;
    while(k!=0 && !nodes.empty()){
        cout << nodes.top() << " ";
        nodes.pop();
        k--;
    }
}

Node* insert(Node* root,int data){
    if(root==nullptr){
        Node* temp=new Node();
        temp->data = data;
        temp->left = temp->right = nullptr;
        return temp;
    }
    else{
        if(root->data>data){
            root->left=insert(root->left,data);
        }
        else if(root->data<data){
            root->right=insert(root->right,data);
        }
        else{
            cout << "Elememt " << data << " already in BST" << endl; 
        }
        return root;
    }
}

void InOrder(Node* root){
    stack<Node*> S;
    S.push(root);
    while (true){
        while(root!=nullptr){
            S.push(root);
            root = root->left;
        }
        if (S.empty()){
            break;
        }
        root = S.top();
        S.pop();
        cout << root->data << " ";
        root = root->right;
    }
}

int main() 
{ 
    // Construct binary tree
    Node* root=nullptr;
    for(int x: {5,4,9,1,2,8,10,11,7}){
        root=insert(root,x);
    }
    InOrder(root);
    return 0;
}
   

    /*cout << endl;
    /
    Find(root1,1); 
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->left->left = newNode(4); 
    root->left->left->left = newNode(21); 
    root->left->right = newNode(5); 
    root->left->right->right = newNode(8); 
    root->right = newNode(3); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->right->right = newNode(19); 
  
    // Function Call 
    Find(root, 3); 
    return 0; 
}*/