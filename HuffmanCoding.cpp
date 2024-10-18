#include<iostream>
#include<utility>
#include<cstdint>
#include<bits/stdc++.h>
#include"node.h"
using namespace std;

// node* Root;     // Global variable

void traverseForHuffmanTable(node* node, unordered_map<char, string>& map, string s = ""){
    if(node->left==nullptr && node->right==nullptr){
        map[node->c]=s;
        return;
    }
    s.push_back('0');
    traverseForHuffmanTable(node->left, map, s);
    s.pop_back();
    s.push_back('1');
    traverseForHuffmanTable(node->right, map, s);
}

void traverse(node* node, string& ans){
    if(node->left==nullptr && node->right==nullptr){
        ans.push_back(node->c);
        return;
    }
    ans.push_back('*');
    traverse(node->left, ans);
    traverse(node->right, ans);
}

pair<string, string> HuffmanCode(string s){
    // finding frequency vector
    unordered_map<char, int> f;
    for(char&c:s){
        if(f.find(c)==f.end())  f[c]=1;
        else                    f[c]++;
    }

    // storing character to priority queue
    priority_queue<node, vector<node>, greater<node>> pq;
    for(auto&p:f){
        pq.push(*(new node(p.first, p.second)));
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

    // traverse hufftree

    // generate huffman table
    unordered_map<char, string> map;
    traverseForHuffmanTable(Root, map);
    cout<<"Huffman Table:"<<endl;
    for(auto&p:map){
        cout<<"'"<<p.first<<"'\t"<<f[p.first]<<"\t"<<p.second<<endl;
    }
    cout<<endl;

    string encode;
    for(char&c:s)   encode+=map[c];
    
    // generate treeString
    string treeString;
    traverse(Root, treeString);
    string temp=treeString;
    treeString="";
    for(char&c:temp){
        if(c=='*')  treeString.push_back('0');
        else{
            treeString.push_back('1');
            treeString.push_back(c);
        }
    }

    return make_pair(treeString, encode);
}
