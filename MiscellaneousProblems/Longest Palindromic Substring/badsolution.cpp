#include <iostream>
#include <string>

using namespace std;

bool isPalendrome(string str) {
  for(int i = 0; i < str.size(); i++) {
    if(str[i] != str[str.size()-i-1])
      return false;
    }
      return true;
}

string longestPalindrome(string s) {
  string longest = "";
  for(int i = 0; i < s.size()-1; i++) {
    for(int j = i+1; j < s.size(); j++) {
      string sub = s.substr(i,j);
      if(isPalendrome(sub) && sub.size() > longest.size())
        longest = sub;
    }
  }
  return longest;
}

int main() {
  string s;
  cin >> s;
  cout << longestPalindrome(s) << endl;
}
