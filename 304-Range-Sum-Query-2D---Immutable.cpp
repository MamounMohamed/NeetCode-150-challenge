class NumMatrix {
public:
    long long prefRow[201][201];
    NumMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            prefRow[i][0] = 1LL* matrix[i][0];
            for (int j = 1; j < matrix[0].size(); j++) {
                prefRow[i][j] = prefRow[i][j - 1] + 1LL* matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        long long ans = 0;
        for (int i = row1; i <= row2; i++) {
            ans += col1 == 0 ? prefRow[i][col2]
                             : prefRow[i][col2] - prefRow[i][col1 - 1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */