#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Function to compute the total expense given a cost matrix and a particular assignment of tasks
int computeTotalExpense(const vector<vector<int>>& matrix, const vector<int>& taskAssignment) {
    int totalExpense = 0;
    int tasks = taskAssignment.size();
    
    for (int i = 0; i < tasks; ++i) {
        totalExpense += matrix[i][taskAssignment[i]];
    }
    
    return totalExpense;
}

// Solves the task assignment problem to minimize total expense
int assignmentProblem(const vector<vector<int>>& matrix) {
    int tasks = matrix.size();
    int lowestExpense = numeric_limits<int>::max();
    vector<int> currentAssignment(tasks);
    
    // Initial assignment
    for (int i = 0; i < tasks; ++i) currentAssignment[i] = i;
    
    // Iterate through all possible assignments to find the one with the lowest expense
    do {
        int expense = computeTotalExpense(matrix, currentAssignment);
        
        if (expense < lowestExpense) lowestExpense = expense;
    } while (next_permutation(currentAssignment.begin(), currentAssignment.end()));
    
    return lowestExpense;
}

int main() {
    vector<vector<int>> sampleMatrix = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    
    vector<vector<int>> largerMatrix = {
        {68, 22, 57, 28, 12, 8},
        {6, 44, 31, 27, 3, 5},
        {15, 58, 10, 48, 1, 44},
        {57, 26, 19, 24, 11, 3}
    };

    cout << "Optimal assignment cost: " << assignmentProblem(sampleMatrix) << endl;
    cout << "Optimal assignment cost: " << assignmentProblem(largerMatrix) << endl;

    return 0;
}