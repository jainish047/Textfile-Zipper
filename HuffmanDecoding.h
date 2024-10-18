#include <bits/stdc++.h>
#include <algorithm>
#include "node.h"
using namespace std;

string Decode(string encode, string treeString)
{
    // generate tree from treeString
    stack<node *> st;
    // node* root = new node();
    // st.push();
    node* root=new node();
    st.push(root);
    for(int i=1; i<treeString.length(); i++){
        node* nn=new node();
        while(st.top()->left!=nullptr && st.top()->right!=nullptr)  st.pop();
        if(st.top()->left==nullptr){
            st.top()->left=nn;
        }else{
            st.top()->right=nn;
        }
        st.push(nn);
        if(treeString[i]=='1'){
            nn->c=treeString[++i];
            st.pop();
        }
    }

    // decoding
    string ans;
    node* temp=root;
    for(char&c:encode){
        if(c=='0')  temp=temp->left;
        else        temp=temp->right;
        if(temp->c!='\0'){
            ans.push_back(temp->c);
            temp=root;
        }
    }

    return ans;
}