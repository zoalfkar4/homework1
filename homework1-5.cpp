#include <iostream>
#include <vector>
#include <algorithm>

bool compareEnvelopes(const std::vector<int>& a, const std::vector<int>& b) {
  if (a[0] == b[0]) {
    return a[1] > b[1];
  }
  return a[0] < b[0];
}

int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
  int n = envelopes.size();
  if (n == 0) {
    return 0;
  }
  std::sort(envelopes.begin(), envelopes.end(), compareEnvelopes);
  std::vector<int> dp(n, 1);
  int maxEnvelopes = 1; 
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (envelopes[i][1] > envelopes[j][1]) {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
    maxEnvelopes = std::max(maxEnvelopes, dp[i]);
  }
  return maxEnvelopes;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> envelopes(n, std::vector<int>(2));
  for (int i = 0; i < n; i++) {
    std::cin >> envelopes[i][0] >> envelopes[i][1];
  }
  int maxRussianDollEnvelopes = maxEnvelopes(envelopes);
  std::cout << maxRussianDollEnvelopes << std::endl;
  return 0;
}
