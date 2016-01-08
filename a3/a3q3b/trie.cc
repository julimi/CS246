#include "trie.h"

using namespace std;

// ctor
TrieNode::TrieNode() {
    isWord = 0;
    for (int i = 0; i < NumChars; i++) {
        letters[i] = NULL;
    } // for
} // TrieNode()

// dtor
TrieNode::~TrieNode() {
    isWord = false;
    for (int i = 0; i < NumChars; i++) {
        if (letters[i]) delete letters[i];
        letters[i] = NULL;
    } // for
} // ~TrieNode

// add word
void TrieNode::insert(const std::string &word) {
    
    // mark the word * at the end
    if (word.size() == 0) {
        isWord = true;
    } else {
        
        // create new node when it is null
        if (letters[word[0] - 'a'] == NULL) {
            letters[word[0] - 'a'] = new TrieNode();
        } // exit
        
        // recursive
        letters[word[0] - 'a']->insert(word.substr(1));
    } // exit
} // insert

// remove word
void TrieNode::remove(const std::string &word) {
    
    int index = 0;
    // remove the * at the end of the word
    if (word.size() == 0 && index == 0) {
        isWord = false;
    } else {
        if (letters[word[0] - 'a'] == NULL) index = 1;
        if (letters[word[0] - 'a']) {
            
            // recursive
            letters[word[0] - 'a']->remove(word.substr(1));
        } // exit
    } // exit
} // remove

// helper func for find
void append(TrieNode *cur,string *ori,string ws,string pre){
    
    // add the prefix of next word
    if (cur->isWord){
        *ori = *ori + " " + pre + ws;
    } // exit
    for (int i = 0; i < NumChars; i++){
        if(cur->letters[i] != NULL){
            
            /* add the later word of the next word
             * behind the prefix */
            char later = i + 'a';
            string nws = ws + later;
            
            // recursive helper func
            append(cur->letters[i],ori,nws,pre);
        } // exit
    } // for
} // append

string TrieNode::find(const string &word){
    int index = 0;
    // copy the current trie
    TrieNode *cur = this;
    for (int i = 0; i < word.size(); i++){
        
        /* break the loop if the word
         * does not exit in this trie */
        if(cur->letters[word[i] - 'a'] == NULL){
            index = 1;
            break;
        } // exit
        cur = cur->letters[word[i] - 'a'];
    } // for
    
    // create a blank string
    string ws = "" ;
    
    // make a copy of word
    string repword = word;
    
    /* index still be 0, the word appear in trie,
     * and go on finding */
    if (index == 0){
        
        // recursive helper func
        append(cur,&ws,"",repword);
        
        // if read the whitespace, cut it
        if(ws[0] == ' '){
            ws = ws.substr(1);
        } // exit
        
        /* at the end, remove the word
         * at the end without star */
        if(ws == ""){
            for(int i = 0; i < NumChars; i++){
                if(cur->letters[i] != NULL){
                    delete cur->letters[i];
                } // exit
            } // for
        } // exit
    } // exit
    return ws;
} // find

// count the num of nodes
int TrieNode::size() {
    
    // the root
    int ans = 1;
    for (int i = 0; i < NumChars; i++) {
        
        // add 1 if there exits word
        if (letters[i]) {
            ans += letters[i]->size();
        } // exit
    } // for
    return ans;
} // size()
