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

// ******************************************************
//           Non Linked-list based solution
// ******************************************************

int nNodes = 1, nString = 0, ROOT = 0, nLetters = 122;

vector<vector<int>> edge(MAXN + 1, vector<int>(nLetters + 1));
vector<int> prefixCount(MAXN + 1);
vector<int> endNode(MAXN + 1);
vector<char> printStrs(MAXN + 1);
vector<string> lexicoStrs;

void init (vector<string> &strs) {
  for(const string &str: strs) {
    int parentNode = ROOT;
    for(const char &ch: str) {
      int childNode = (int) ch;
      if(!edge[parentNode][childNode]) edge[parentNode][childNode] = nNodes++;
      parentNode = edge[parentNode][childNode];
      prefixCount[parentNode]++;
    }
    nString++;
    endNode[parentNode]++;
  }
}

void _getLexicalOrderList (int node = ROOT, int id = 0) {
  if(endNode[node]) {
    string output(printStrs.begin(), printStrs.begin() + id);
    lexicoStrs.push_back(output);
  }
  for(int i = 0; i < nLetters; i++) {
    if(edge[node][i]) {
      printStrs[id] = ((char) i);
      checkTrie(edge[node][i], id + 1);
    }
  }
}

void clear() {
  for(int i = 0; i < nNodes; i++) {
    endNode[i] = prefixCount[i] = 0;
    for(int j = 0; j < nLetters; j++) edge[i][j] = 0;
  } 
  nNodes = 1;
  nString = 0;
}
