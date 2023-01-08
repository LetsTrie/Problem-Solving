vector <int> dp(MAXN + 1, -1);

int fib(int n) {
  if (n <= 1) return n;
  if (dp[n] != -1) return dp[n];
  dp[n] = fib(n - 1) + fib(n - 2);
  return dp[n];
}
