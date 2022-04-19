#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    int hd;
    Node *left,*right;
    Node(int d){
        data = d;
        this->left = this->right =nullptr;
    }
};

void top(Node *root,int dist,int level,auto &m)
{
    if(root==nullptr)
        return;
    if(m.find(dist)==m.end())
    {
        m[dist]={root->data,level};
    }
    else
    {
        if(level<m[dist].second) {
            m[dist].second = level;
            m[dist].first = root->data;
        }
    }
    top(root->left,dist-1,level+1,m);
    top(root->right,dist+1,level+1,m);
}

void printtop(Node *root)
{
    map<int,pair<int,int>> m; //  < h-dist, pair<data,level> >
    top(root, 0,0,m);

    for(auto it:m )
        cout<<it.second.first<< " ";
}


void printtop_it(Node *root){
    if(root==nullptr){
        return;
    }

    queue<Node*>q;
    map<int,int>m; //   <hd,data>
    int d=0;
    root->hd=d;

    q.push(root);
    while(q.size())
    {
   //     cout<<root->hd<<endl;
        d=root->hd;

        if(m.count(d)==0){
            m[d]=root->data;
        }

        if(root->left){
            root->left->hd=d-1;
            q.push(root->left);
        }
        if(root->right){
            root->right->hd=d+1;
            q.push(root->right);
        }
        q.pop();
        root=q.front();
    }
    cout<< "Top-View\n";
    for(auto i=m.begin();i!=m.end();i++){
        cout<<i->second<< " ";
    }

}


int main()
{
    Node* root = nullptr;

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    //T=> o(nlog(n)) S=o(n)
    printtop(root);
    cout<<endl;
    printtop_it(root);

}
