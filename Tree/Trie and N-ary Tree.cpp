#include <unordered_map>

/* Fixed number of children (array-based) */
struct TrieNode {
    TrieNode* children[26];  // n = 26
    bool isEnd;
};

/* Dynamic number of children (map-based) */
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;
};


struct TrieNode {
    TrieNode* child[10];  // n = 0–9
    bool isEnd;
};


/*

Trie is an n-ary tree where n is fixed or dynamic.

Examples:

	Lowercase English → n = 26
	Digits only → n = 10
	Upper + lower case → n = 52
	ASCII → n = 128
	Unicode → very large (usually handled dynamically)

*/