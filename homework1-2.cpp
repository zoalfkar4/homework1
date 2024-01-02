#include <iostream>

int main() {
  int x1, y1, x2, y2, X1, Y1, X2, Y2;
  std::cout << "Enter the coordinates of the first rectangle: ";
  std::cin >> x1 >> y1 >> x2 >> y2;
  std::cout << "Enter the coordinates of the second rectangle: ";
  std::cin >> X1 >> Y1 >> X2 >> Y2;
  bool overlap = true;
  if (x1 >= X2 || X1 >= x2) {
    overlap = false;
  }
  if (y1 >= Y2 || Y1 >= y2) {
    overlap = false;
  }
  if (overlap) {
    std::cout << "True" << std::endl;
  } else {
    std::cout << "False" << std::endl;
  }
  return 0;
}

