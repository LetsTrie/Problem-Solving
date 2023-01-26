// 1. Middle of 1 to N is: if (N & 1) then (N + 1) / 2 else (N / 2) or (N / 2) + 1
// 2. ASCII code: [A-Z, 65-90], [a-z,  97-122], [0-9, 48-57]

// string int_to_str (int n) { stringstream ss; ss << n; string str; ss >> str; return str; }
// int str_to_int (string str) { int n; stringstream ss; ss << str; ss >> n; return n; }

string int_to_str (int n) { return to_string(n); }
int str_to_int (string str) { return stoi(str); }

// In a 2D Matrix, If we can rotate any row/columns any number of times to get the maximum value in each cell of the upper left, result will be
// Visualize it. It is beautiful.
for(int i = 0; i < len / 2; i++) {
  for(int j = 0; j < len / 2; j++) {
     int max_val =  max(mat[i][j], max(mat[i][len - 1 - j], max(mat[len - 1 - i][j], mat[len - 1 - i][len - 1 - j])));
  }
}

// 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
// 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

// Pattern finding problems
// 1. https://leetcode.com/problems/xor-operation-in-an-array/