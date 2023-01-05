#include<bits/stdc++.h>
 
using namespace std;
 
#define DEBUG(x) cout << #x << " = " << x << endl;

typedef long long LL;

/*
 * Use-of: Binary Search
 * 1. https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
 * 2. https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B
 * 3. https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C
 * 4. https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
 */

int binarySearch(int array[], int arraySize, int target) {
  int low = 0;
  int high = arraySize - 1;
  int index = -1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (array[mid] == target) index = mid;
    else if (array[mid] < target) low = mid + 1;
    else high = mid - 1;
    
    if (array[mid] == target) break;
  }

  return index;
}

// Key-point: Maximum index of an array element not greater than the target!
int closestToLeft(int array[], int arraySize, int target) {
  int low = 0;
  int high = arraySize - 1;
  int index = -1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (array[mid] <= target) {
      index = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return index;
}

// Key-point: Minimum index of an array element not less than the target!
int closestToRight(int array[], int arraySize, int target) {
  int low = 0;
  int high = arraySize - 1;
  int index = arraySize;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (array[mid] >= target) {
      index = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return index + 1;
}

// ***************************************************************************************************
// ***************************************************************************************************

/*
 * Use-of: Dynamic Programming
 * 1. https://leetcode.com/problems/fibonacci-number/
 * 2. https://leetcode.com/problems/climbing-stairs/
 * 3. https://leetcode.com/problems/powx-n/
 */

// Problem 1: Fibonacci Number
vector <int> dp(MAXN + 1, -1);
int fib(int n) {
  if (n <= 1) return n;
  if (dp[n] != -1) return dp[n];
  dp[n] = fib(n - 1) + fib(n - 2);
  return dp[n];
}

// Problem 2: Binary Exponentiation (Big Mod) [Calculate (a^p)%m]
// Explanation: https://cp-algorithms.com/algebra/binary-exp.html
LL bigmod(LL a, LL p, LL m) {
  LL res = 1 % m, x = a % m;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}

// ***************************************************************************************************
// ***************************************************************************************************

/*
 * Use-of: Stack 
 * 1. https://leetcode.com/problems/valid-parentheses/
 */

// Problem 1: Valid Parentheses
bool isValid(string s) {
  stack <char> parenthesis;
  for (auto const & ch: s) {
    if (ch == '(' || ch == '{' || ch == '[') parenthesis.push(ch);
    else {
      if (parenthesis.empty()) return false;
      else if (ch == ')' && parenthesis.top() == '(') parenthesis.pop();
      else if (ch == '}' && parenthesis.top() == '{') parenthesis.pop();
      else if (ch == ']' && parenthesis.top() == '[') parenthesis.pop();
      else return false;
    }
  }

  return parenthesis.empty();
}

// ***************************************************************************************************
// ***************************************************************************************************

// Math
const int N = 120, M = 120, F = 30;
vector<vector<LL>> nCr(N, vector<LL> (M, -1));
vector<LL> factorial;

LL calculateNcR(LL n, LL r) {
  if(n < r) return 0;
  if(n == r || r == 0) return 1;
  if(nCr[n][r] != -1) return nCr[n][r];

  return nCr[n][r] = calculateNcR(n - 1, r) + calculateNcR(n - 1, r - 1);
}

// Formula: nc1+nc2+nc3+nc4+...+ncn = (2^n)-1
// Formula: 1+2+3+...+n = n(n+1)/2
// Problem: https://leetcode.com/problems/number-of-substrings-with-only-1s/

void calculateFactorial(int n) {
  factorial[0] = 1;
  for(int i = 1; i <= n; i++) factorial[i] = factorial[i - 1] * i;
}

LL calculateGcd(LL n, LL m) {
  while(m > 0) {
    n = n % m; n = n ^ m; m = m ^ n; n = n ^ m;
  }
  return n;
}

LL calculateLcm(LL n, LL m) {
  return (n * m) / calculateGcd(n, m);
}


// ***************************************************************************************************
// ***************************************************************************************************

// String DS: Trie [Non Linked-List Solution]
// 1. https://leetcode.com/problems/longest-common-prefix/
// 2. https://leetcode.com/problems/lexicographical-numbers/
// 3. https://leetcode.com/problems/implement-trie-prefix-tree/

int nNodes = 1, nString = 0, ROOT = 0, nLetters = 122;

vector<vector<int>> edge(MAXN + 1, vector<int>(nLetters + 1));
vector<int> prefixCount(MAXN + 1);
vector<int> endNode(MAXN + 1);
vector<char> printStrs(MAXN + 1);
vector<string> lexicoStrs;

void initTrie (vector<string> &strs) {
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

void checkTrie(int node = ROOT, int id = 0) {
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

void clearTrie() {
  for(int i = 0; i < nNodes; i++) {
    endNode[i] = prefixCount[i] = 0;
    for(int j = 0; j < nLetters; j++) edge[i][j] = 0;
  } 
  nNodes = 1;
  nString = 0;
}

// ***************************************************************************************************
// ***************************************************************************************************

// Miscellaneous
// 1. Middle of 1 to N is: if (N & 1) then (N + 1) / 2 else (N / 2) or (N / 2) + 1
// 2. ASCII code: [A-Z, 65-90], [a-z,  97-122], [0-9, 48-57]

string intToStr (int n) {
  stringstream ss; ss << n; 
  string str; ss >> str;
  return str;
}

int strToInt (string str) {
  return stoi(str);
}
