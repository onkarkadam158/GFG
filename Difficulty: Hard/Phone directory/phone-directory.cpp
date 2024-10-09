//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Node{
    public:
    map<char,Node*>mp;
    bool isEndNode=false;

    bool isAdded(char ch){
        return mp.find(ch)!=mp.end();
    }    
    void addNewNode(char ch,Node* newNode){
        mp[ch]=newNode;
    }
    Node* getNext(char ch){
        return mp[ch];
    }
    bool isEnd(){
        return isEndNode;
    }
    void setEnd(){
        isEndNode=true;
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root= new Node();
    }
    void addToTrie(string &s){
        Node* node=root;
        for(auto ch:s){
            if(!node->isAdded(ch)){
                node->addNewNode(ch,new Node());
            }
            node=node->getNext(ch);
        }
        node->setEnd();
    }
    vector<string> search(string &s){
        Node* node=root;
        for(auto ch:s){
            if(!node->isAdded(ch)){
                return {"0"};
            }
            node=node->getNext(ch);
        }
        vector<string>res;
        string temp=s;
        dfs(node,res,temp);
        return res;
    }
    void dfs(Node* node,vector<string>&res,string& temp){
        if(node->isEnd()){
            res.push_back(temp);
        }
        for(auto ch:node->mp){
            temp+=ch.first;
            dfs(node->getNext(ch.first),res,temp);
            temp.pop_back();
        }
    }
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>>res;
        Trie trie;
        for(int i=0;i<n;i++){
            trie.addToTrie(contact[i]);
        }
        string temp="";
        for(int i=0;i<s.size();i++){
            temp+=s[i];
            res.push_back(trie.search(temp));
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends