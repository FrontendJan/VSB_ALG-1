#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

std::vector<int> generateRandomVector(int length, int minVal, int maxVal) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(minVal, maxVal);

    std::vector<int> result(length);
    for (int i = 0; i < length; ++i) {
        result[i] = distribution(gen);
    }
    return result;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void shakerSort(std::vector<int>& A) {
    int left = 0;
    int right = A.size() - 1;

    while (left < right) {
        // Left to right pass
        for (int i = left; i < right; ++i) {
            if (A[i] > A[i + 1]) {
                swap(A[i], A[i + 1]);
            }
        }
        right--;

        // Right to left pass
        for (int i = right; i > left; --i) {
            if (A[i - 1] > A[i]) {
                swap(A[i - 1], A[i]);
            }
        }
        left++;
    }
}

int main() {
    int n = 1000;  // Example size of the vector
    std::vector<int> randomVector = generateRandomVector(n, 0, 100);

    // Compare the performance of Shaker sort and std::swap
    auto start = std::chrono::high_resolution_clock::now();
    shakerSort(randomVector);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> shakerSortDuration = end - start;
    std::cout << "Time taken to sort the vector using Shaker sort: " << shakerSortDuration.count() << " seconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::sort(randomVector.begin(), randomVector.end());
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> stdSortDuration = end - start;
    std::cout << "Time taken to sort the vector using std::sort: " << stdSortDuration.count() << " seconds" << std::endl;

    return 0;
}