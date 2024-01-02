#include <iostream>
#include <vector>

std::vector<std::string> findMatchingWords(
    const std::vector<std::string>& words, const std::string& pattern) {
  std::vector<std::string> result;
  for (const std::string& word : words) {
    if (word.length() != pattern.length()) {
      continue;
    }
    std::vector<char> wordToPattern(26, '\0');
    std::vector<char> patternToWord(26, '\0');
    bool isMatch = true;
    for (int i = 0; i < word.length(); i++) {
      char w = word[i];
      char p = pattern[i];
      if (wordToPattern[w - 'a'] != '\0' && wordToPattern[w - 'a'] != p) {
        isMatch = false;
        break;
      }
      if (patternToWord[p - 'a'] != '\0' && patternToWord[p - 'a'] != w) {
        isMatch = false;
        break;
      }
      wordToPattern[w - 'a'] = p;
      patternToWord[p - 'a'] = w;
    }
    if (isMatch) {
      result.push_back(word);
    }
  }
  return result;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::string> words(n);
  for (int i = 0; i < n; i++) {
    std::cin >> words[i];
  }
  std::string pattern;
  std::cin >> pattern;
  std::vector<std::string> matchingWords = findMatchingWords(words, pattern);
  for (const std::string& word : matchingWords) {
    std::cout << word << " ";
  }
  return 0;
}
