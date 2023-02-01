// Valid Parentheses: https://leetcode.com/problems/valid-parentheses/
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
