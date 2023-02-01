// Trie
// Problem: 1 - https://leetcode.com/problems/longest-common-prefix/
// Problem: 2 - https://leetcode.com/problems/lexicographical-numbers/
// Problem: 3 - https://leetcode.com/problems/implement-trie-prefix-tree/
// Problem: 4 - https://leetcode.com/problems/search-suggestions-system/
// Problem: 5 - https://www.hackerrank.com/challenges/one-month-preparation-kit-sparse-arrays/problem

// ******************************************************
//             Linked-list based solution
// ******************************************************

// Change nLetters/strToASCII according to problem!
const int nLetters = 26;

int strToASCII (char ch) { return ch - 'a'; }
char ASCIItoStr(int ch) { return ch + 'a'; }

class TrieNode {
  public:
    TrieNode *next[nLetters + 1] = { nullptr };
    int serial = 0;
    int prefixCount = 0;
    bool isEndOne = false;
    int occurance = 0;

    TrieNode(int _x = 0) : serial(_x) {}
};

class Trie {
    TrieNode *root;
    int nString = 0;
    int nNode = 1;
    vector<string> lexicoStrings;

public:
    Trie() { root = new TrieNode(); }
    
    void insert(string word) {
      TrieNode *p = root;

      for(char &ch: word) {
        int val = strToASCII(ch);
        if(p->next[val] == NULL) p->next[val] = new TrieNode(nNode++);
        p = p->next[val];
        p->prefixCount++;
      }
      nString++;
      p->isEndOne=true;
      p->occurance++;
    }
  
   void solve () {
    // write your code here...
   }

  private:
    TrieNode* _findByKey (string key) {
      TrieNode *node = root;
      for(char &ch: key) {
        int value = strToASCII(ch);
        node = node->next[value];
        if(node == NULL) break;
      }
      return node;
    }

    void _getLexicalOrderList (TrieNode *node, string &cur, vector<string> &res) {
      if(node->isEndOne == true) res.push_back(cur);
      for(int i = 0; i < nLetters; i++) {
        if(node->next[i] != NULL) {
          cur += ASCIItoStr(i);
          _getLexicalOrderList(node->next[i], cur, res);
          cur.pop_back();
        }
      }
    }
};