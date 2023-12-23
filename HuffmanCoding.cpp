#include<iostream>
#include<utility>
#include<cstdint>
#include<bits/stdc++.h>
#include"node.h"
using namespace std;

// node* Root;     // Global variable

vector<pair<vector<bool>, char>>& traverse(node* root, vector<pair<vector<bool>, char>>& v, vector<bool> a){
    if(root->c=='\0'){
        // cout<<root->f<<endl;
        a.push_back(false);
        v=traverse(root->left, v, a);
        a.pop_back();
        a.push_back(true);
        v=traverse(root->right, v, a);
    }
    else
        v.push_back(make_pair(a, root->c));
    return v;
}

vector<bool> HuffmanCode(string s)
{
// finding frequency vector
    vector<int> f(95, 0);
    for(int i=0; i<s.length(); i++)
        f[s[i]-32]++;

// storing non-zero frequency character to priority queue
    priority_queue<node, vector<node>, greater<node>> pq;
    for(int i=0; i<f.size(); i++){
        if(f[i]!=0){
            node* n1=new node(char(32+i), f[i]);
            pq.push(*n1);
        }
    }

// converting priority queue into tree
    while(pq.size()!=1){
        node* a=new node(pq.top().c, pq.top().f);
        a->left=pq.top().left;
        a->right=pq.top().right;

        pq.pop();

        node* b=new node(pq.top().c, pq.top().f);
        b->left=pq.top().left;
        b->right=pq.top().right;

        pq.pop();

        node* n1=new node('\0', a->f+b->f);
        if(a->f<b->f)   {n1->left=a;n1->right=b;/*cout<<"a";*/}
        else            {n1->left=b;n1->right=a;/*cout<<"b";*/}

        pq.push(*n1);
    }
    cout<<endl;

// getting huffman table from tree
    node root=pq.top();
    pq.pop();
    node* Root=&root;

    // traverse_hufftree(Root);
    vector<pair<vector<bool>, char>> a;
    vector<bool> v;
    vector<pair<vector<bool>, char>>& b=traverse(Root, a, v);
    
    cout<<"Huffman Table: "<<endl;
    for(int i=0; i<b.size(); i++){
        cout<<"'"<<b[i].second<<"'    ";
        for(int j=0; j<b[i].first.size(); j++)      cout<<b[i].first[j];
        cout<<endl;
    }
    cout<<endl;

// Encoded string from huffman table
    vector<bool> w;

    for(int i=0; i<s.length(); i++){
        for(int j=0; j<b.size(); j++){
            if(s[i]==b[j].second){
                for(int k=0; k<b[j].first.size(); k++){
                    w.push_back(b[j].first[k]);
                }
            }
        }
    }

    cout<<"\nEncoded: "<<endl;
    for(int i=0; i<w.size(); i++)
        cout<<w[i];

// Decoding huffman code to string
    cout<<"\n\nDecoded: "<<endl;
    string ss;
    node* r=Root;
    for(int i=0; i<w.size(); i++){
        if(w[i]==false){
            r=r->left;
        }
        else{
            r=r->right;
        }
        if(r->c!='\0'){
            ss.push_back(r->c);
            r=Root;
        }
    }

    cout<<ss;
}