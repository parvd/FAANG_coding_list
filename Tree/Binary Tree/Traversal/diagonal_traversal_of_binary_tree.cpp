#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int data){
        this->data=data;
        left=right=nullptr;
    }
};

void solveutil(Node *root,int d,auto &m){

    if(!root)
        return ;

    m[d].push_back(root->data);

    solveutil(root->left,d+1,m);
    solveutil(root->right,d,m);
}

void solve(Node *root){

    map<int,vector<int>> m;
    solveutil(root,0,m);

    for(auto i : m){

        cout<<"level "<<i.first<<"=";
        vector<int>v = i.second ;
        for(auto it:v){
            cout<< it<<" ";
        }
        cout<<endl;
    }

}
vector <vector <int>> result;

void iterative(Node* root){
    if(root == NULL)
        return;
 
    queue <Node*> q;
    q.push(root);
 
    while(!q.empty())
    {
        int size = q.size();
        vector <int> answer;
 
        while(size--)
        {
            Node* temp = q.front();
            q.pop();
 
            // traversing each component;
            while(temp)
            {
                answer.push_back(temp->data);
 
                if(temp->left)
                    q.push(temp->left);
 
                temp = temp->right;
            }
        }
        result.push_back(answer);
    }
    for(int i=0 ; i<result.size() ; i++)
    {
        for(int j=0 ; j<result[i].size() ; j++)
            cout<<result[i][j]<<"  ";
        cout<<endl;
    }
}


int main(){

    Node* root = nullptr;

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    solve(root);
    iterative(root);
}



