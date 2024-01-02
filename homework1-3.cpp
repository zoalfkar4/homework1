#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool compare(std::pair<int, int>& p1, std::pair<int, int>& p2) {
  return (p1.first * p1.first + p1.second * p1.second) < (p2.first * p2.first + p2.second * p2.second);
}

std::vector<std::vector<int>> kClosestPoints(std::vector<std::vector<int>>& points, int k) {
  std::vector<std::pair<int, int>> distances;
  for (auto& point : points) {
    distances.push_back({point[0], point[1]});
  }
  sort(distances.begin(), distances.end(), compare);
  std::vector<std::vector<int>> result;
  for (int i = 0; i < k; i++) {
    result.push_back({distances[i].first, distances[i].second});
  }
  return result;
}

int main() {
  int N;
  int k;
  std::cin >> N >> k;
  std::vector<std::vector<int>> points(N, std::vector<int>(2));
  for (int i = 0; i < N; i++) {
    std::cin >> points[i][0] >> points[i][1];
  }
  std::vector<std::vector<int>> closestPoints = kClosestPoints(points, k);
  for (int i = 0; i < closestPoints.size(); i++) {
    std::cout << closestPoints[i][0] << " " << closestPoints[i][1] << std::endl;
}

    
    return 0;
}
