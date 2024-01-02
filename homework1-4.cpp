#include <iostream>
#include <vector>

std::vector<std::vector<int>> generateSpiralMatrix(int n) {
  std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
  int num = 1;
  int top = 0, bottom = n - 1, left = 0, right = n - 1;
  while (num <= n * n) {
    for (int i = left; i <= right; i++) {
      matrix[top][i] = num++;
    }
    top++;
    for (int i = top; i <= bottom; i++) {
      matrix[i][right] = num++;
    }
    right--;
    for (int i = right; i >= left; i--) {
      matrix[bottom][i] = num++;
    }
    bottom--;
    for (int i = bottom; i >= top; i--) {
      matrix[i][left] = num++;
    }
    left++;
  }
  return matrix;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> spiralMatrix = generateSpiralMatrix(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << spiralMatrix[i][j] << " ";
    }
  std::cout << std::endl;
  }
  return 0;
}
