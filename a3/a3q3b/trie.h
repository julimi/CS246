#ifndef __TRIE_H__
#define __TRIE_H__
#include <string>

const int NumChars = 26;

struct TrieNode {
    bool isWord;
    TrieNode *letters[NumChars];
    TrieNode();
    ~TrieNode();

    void insert(const std::string &word);
    void remove(const std::string &word);
    std::string find(const std::string &word);
    int size();
}; // TrieNode

#endif
