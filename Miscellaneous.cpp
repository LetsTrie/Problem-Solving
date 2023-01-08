// 1. Middle of 1 to N is: if (N & 1) then (N + 1) / 2 else (N / 2) or (N / 2) + 1
// 2. ASCII code: [A-Z, 65-90], [a-z,  97-122], [0-9, 48-57]

string intToStr (int n) { stringstream ss; ss << n; string str; ss >> str; return str; }
int strToInt (string str) { return stoi(str); }
