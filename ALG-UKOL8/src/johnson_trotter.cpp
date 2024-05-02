#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform the Johnson-Trotter algorithm
void johnson_trotter(int n) {
    // Initialize the first permutation
    vector<pair<int, bool>> permutation(n);
    for (int i = 0; i < n; i++) {
        permutation[i] = make_pair(i + 1, false);
    }

    // Print the initial permutation
    cout << "Initial permutation: ";
    for (const auto& p : permutation) {
        cout << (p.second ? "<- " : "-> ") << p.first << " ";
    }
    cout << endl;

    // Perform the Johnson-Trotter algorithm
    int mobile = 0;
    while (true) {
        // Find the largest mobile element
        int largest_mobile = -1;
        for (int i = 0; i < n; i++) {
            if (permutation[i].second && (i == n - 1 || permutation[i].first > permutation[i + 1].first)) {
                largest_mobile = i;
            }
        }

        // If no mobile element is found, break
        if (largest_mobile == -1) {
            break;
        }

        // Swap the largest mobile element with the element it points to
        int swap_index = largest_mobile + (permutation[largest_mobile].second ? 1 : -1);
        swap(permutation[largest_mobile], permutation[swap_index]);

        // Reverse the directions of all elements larger than the largest mobile element
        for (int i = 0; i < n; i++) {
            if (permutation[i].first > permutation[largest_mobile].first) {
                permutation[i].second = !permutation[i].second;
            }
        }

        // Print the permutation
        cout << "Permutation: ";
        for (const auto& p : permutation) {
            cout << (p.second ? "<- " : "-> ") << p.first << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    johnson_trotter(n);

    // Compare with std::next_permutation
    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
    }

    cout << "Permutations using std::next_permutation:" << endl;
    sort(permutation.begin(), permutation.end());
    do {
        for (int i : permutation) {
            cout << i << " ";
        }
        cout << endl;
    } while (next_permutation(permutation.begin(), permutation.end()));

    return 0;
}