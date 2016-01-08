#include <iostream>
#include <string>
#include <fstream>
#include "trie.h"
using namespace std;


// help to read order and excute
void helper(string &order, TrieNode *trie,string &word, istream &in){
    while ( in >> order ){
        switch ( order[0] ) {
            case ('+'):     // add new word
                in >> word;
                trie->insert(word);
                break;
            
            case ('-'):     // make isWord false
                in >> word;
                trie->remove(word);
                break;
            
            case ('?'):     // find word and print, delete word has "-"
                in >> word;
                cout << trie->find(word) << endl;
                break;
                
            case ('$'):     // print num of nodes
                cout << trie->size() << endl;
                break;
                
            case ('i'):     //include the file and get order in txt
                in >> word;
                ifstream f(word.c_str());
                helper(order,trie,word,f);
                break;
                
        } // switch
    } // while
}// main



int main(){
    string order;     //to store orders
    string word;      //to store the prefix
    
    //construct a TrieNode
    TrieNode* trie = new TrieNode();
    // help to read order and execute
    helper(order,trie,word,cin);
    // delete Trienode
    delete trie;
}
