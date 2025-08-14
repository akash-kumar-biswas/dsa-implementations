#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    bool isEndOfWord;
    TrieNode* child[26];

    TrieNode(){
        isEndOfWord = false;
        for(int i = 0; i < 26; i++){
            child[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
      root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto cha: word){
            if(curr->child[cha - 'a'] == nullptr)
                curr->child[cha - 'a'] = new TrieNode();
            curr = curr->child[cha - 'a'];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto cha: word){
            if(curr->child[cha - 'a'] == nullptr)
                return false;
            curr = curr->child[cha - 'a'];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto cha: prefix){
            if(curr->child[cha - 'a'] == nullptr)
                return false;
            curr = curr->child[cha - 'a'];
        }
        return true;
    }
};

int main(){
    Trie* obj = new Trie();
    obj->insert("apple");
    obj->insert("bananna");

    if(obj->search("apple"))
        cout << "word exists" << endl;
    else
        cout << "word doesn't exist"<<endl;

    if(obj->startsWith("app"))
        cout << "word starts with" << endl;
    else
        cout << "word doesn't start with"<<endl;
    return 0;
}