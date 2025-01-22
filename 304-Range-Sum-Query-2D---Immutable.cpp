class NumMatrix {
public:
    int pref[201][201];
    NumMatrix(vector<vector<int>>& matrix) {
        memset(pref , 0 , sizeof(pref));
        for(int i = 0 ; i<matrix.size();i++){
            for(int j = 0 ; j<matrix[0].size();j++)
                pref[i+1][j+1] = matrix[i][j];
        }

        for(int i = 1 ; i< matrix.size()+1; i++){
            for(int j = 2 ; j < matrix[0].size()+1;j++){
                pref[i][j] += pref[i][j-1];
            }
        }
        for(int i = 2 ; i<matrix.size()+1 ; i++){
            for(int j = 1 ; j<matrix[0].size()+1;j++){
                pref[i][j]+=pref[i-1][j];
            }
        }

    }

    long long sumRegion(int row1, int col1, int row2, int col2) {
       row1++ , row2++,col1++,col2++;
        return pref[row2][col2] - pref[row1-1][col2] - pref[row2][col1-1] + pref[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */