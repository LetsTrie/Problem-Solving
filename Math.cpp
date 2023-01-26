const int N = 120, M = 120, F = 30;
vector<vector<LL>> nCr(N, vector<LL> (M, -1));
vector<LL> fact;

LL _nCr(LL n, LL r) {
  if(n < r) return 0;
  if(n == r || r == 0) return 1;
  if(nCr[n][r] != -1) return nCr[n][r];

  return nCr[n][r] = _nCr(n - 1, r) + _nCr(n - 1, r - 1);
}

void _factorial(int n) {
  fact[0] = 1;
  for(int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
}

LL _gcd(LL n, LL m) {
  while(m > 0) {
    n = n % m; n = n ^ m; m = m ^ n; n = n ^ m;
  }
  return n;
}

LL _lcm(LL n, LL m) {
  return (n * m) / _gcd(n, m);
}

int digitSum(int n) {
    int sum = 0;
    while(n) sum += (n % 10), n /= 10;
    return sum; 
}

// Formula: nc1+nc2+nc3+nc4+...+ncn = (2^n)-1
// Formula: 1+2+3+...+n = n(n+1)/2
// Problem: https://leetcode.com/problems/number-of-substrings-with-only-1s/
// Problem: https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
