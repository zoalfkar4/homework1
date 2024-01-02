#include <iostream>
#include <vector>
#include <algorithm>

void backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& result, int start) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        if (i != start && nums[i] == nums[start])
            continue;
        std::swap(nums[start], nums[i]);
        backtrack(nums, result, start + 1);
        std::swap(nums[start], nums[i]);
    }
}

std::vector<std::vector<int>> sequences(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;
    backtrack(nums, result, 0);
    return result;
}

int main() {
    int n;
    std::cout << "Enter the length of the sequence: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter the sequence: ";
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    std::vector<std::vector<int>> permutations = sequences(nums);

    std::cout << "All possible unique permutations:" << std::endl;
    for (const auto& permutation : permutations) {
        for (const auto& num : permutation) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
