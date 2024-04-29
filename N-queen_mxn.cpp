#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int countSolutions;
    vector<bool> colUsed;

    bool canPlace(int row, int col, int m, int n) {
        // Check if the position is forbidden due to the sum of indices divisible by 4
        if ((row + col) % 4 == 0) {
            return false;
        }
        // Check if the column is already used
        if (colUsed[col]) {
            return false;
        }
        return true;
    }

    void placeQueens(int row, int m, int n) {
        if (row == m) {
            countSolutions++;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (canPlace(row, col, m, n)) {
                colUsed[col] = true;
                placeQueens(row + 1, m, n);
                colUsed[col] = false;
            }
        }
    }

public:
    int countPlacements(int m, int n) {
        countSolutions = 0;
        colUsed.assign(n, false);
        placeQueens(0, m, n);
        return countSolutions;
    }
};

int main() {
    int m, n;
    cin >> m;
    cin >> n;
    Solution sol;
    cout << sol.countPlacements(m, n) << endl;
    return 0;
}
