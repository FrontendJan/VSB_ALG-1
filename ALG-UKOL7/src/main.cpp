#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Custom hash function for std::vector<int>
struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        size_t seed = 0;
        for (int i : v) {
            seed ^= std::hash<int>()(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

// Custom equality function for std::vector<int>
struct VectorEqual {
    bool operator()(const std::vector<int>& a, const std::vector<int>& b) const {
        return a == b;
    }
};

// Function to calculate the Manhattan distance heuristic
int manhattanDistance(const vector<int>& state) {
    int distance = 0;
    for (int i = 0; i < 9; ++i) {
        if (state[i] != 0) {
            int x = i % 3, y = i / 3;
            int goalX = (state[i] - 1) % 3, goalY = (state[i] - 1) / 3;
            distance += abs(x - goalX) + abs(y - goalY);
        }
    }
    return distance;
}

// Function to print the puzzle state
void printState(const vector<int>& state) {
    for (int i = 0; i < 9; ++i) {
        cout << state[i] << " ";
        if ((i + 1) % 3 == 0) cout << endl;
    }
    cout << endl;
}

// Function to solve the puzzle using A* search
void solvePuzzleAStar(vector<int> initialState) {
    auto cmp = [](const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
        return a.first > b.first;
    };
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(cmp)> pq(cmp);
    unordered_set<vector<int>, VectorHash, VectorEqual> visited;  // Using custom hash and equality functions
    pq.push({manhattanDistance(initialState), initialState});
    visited.insert(initialState);
    while (!pq.empty()) {
        vector<int> state = pq.top().second;
        pq.pop();
        if (manhattanDistance(state) == 0) {
            cout << "Solution found:" << endl;
            printState(state);
            return;
        }
        int blankPos = find(state.begin(), state.end(), 0) - state.begin();
        int x = blankPos % 3, y = blankPos / 3;
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i], newY = y + dy[i];
            if (newX >= 0 && newX < 3 && newY >= 0 && newY < 3) {
                vector<int> newState = state;
                swap(newState[y * 3 + x], newState[newY * 3 + newX]);
                if (!visited.count(newState)) {
                    pq.push({manhattanDistance(newState), newState});
                    visited.insert(newState);
                }
            }
        }
    }
    cout << "No solution found." << endl;
}

// Function to solve the puzzle using DFS up to a given depth
void solvePuzzleDFS(vector<int> state, int depth) {
    if (depth == 0) {
        printState(state);
        return;
    }
    int blankPos = find(state.begin(), state.end(), 0) - state.begin();
    int x = blankPos % 3, y = blankPos / 3;
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i], newY = y + dy[i];
        if (newX >= 0 && newX < 3 && newY >= 0 && newY < 3) {
            vector<int> newState = state;
            swap(newState[y * 3 + x], newState[newY * 3 + newX]);
            solvePuzzleDFS(newState, depth - 1);
        }
    }
}

int main() {
    vector<int> initialState = {1, 2, 3, 4, 0, 5, 7, 8, 6};
    cout << "Initial state:" << endl;
    printState(initialState);
    cout << "Solving using A*:" << endl;
    solvePuzzleAStar(initialState);
    cout << "Solving using DFS up to depth 3:" << endl;
    solvePuzzleDFS(initialState, 3);
    return 0;
}