const int N = 120, M = 120, F = 30;
vector<vector<LL>> nCr(N, vector<LL> (M, -1));
vector<LL> fact;

LL _nCr(LL n, LL r) {
  if(n < r) return 0;
  if(n == r || r == 0) return 1;
  if(nCr[n][r] != -1) return nCr[n][r];

  return nCr[n][r] = _nCr(n - 1, r) + _nCr(n - 1, r - 1);
}

// nCr = (first "r" values of "n!") / (r!)
// nC2 = (n * (n - 1)) / 2
// nC3 = (n * (n - 1) * (n - 2)) / (3 * 2 * 1) 

void _factorial(int n) {
  fact[0] = 1;
  for(int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
}

LL _gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

LL _lcm(LL n, LL m) {
  return (n * m) / _gcd(n, m);
}

int digitSum(int n) {
    int sum = 0;
    while(n) sum += (n % 10), n /= 10;
    return sum; 
}

int _fib(int n) {
  if (n <= 1) return n;
  if (fib[n] != -1) return fib[n];
  fib[n] = _fib(n - 1) + _fib(n - 2);
  return fib[n];
}

// Formula: nc1+nc2+nc3+nc4+...+ncn = (2^n)-1
// Formula: 1+2+3+...+n = n(n+1)/2
// Problem: https://leetcode.com/problems/number-of-substrings-with-only-1s/
// Problem: https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
