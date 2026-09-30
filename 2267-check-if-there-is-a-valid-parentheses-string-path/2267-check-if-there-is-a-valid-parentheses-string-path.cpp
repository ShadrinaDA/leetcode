class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if (grid[0][0] == ')' || (rows + cols - 1) % 2 != 0) {
            return false;
        }
        vector<vector<unordered_set<int>>> table(rows, vector<unordered_set<int>>(cols));
        table[0][0].insert(1);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
               if (i != 0) {
                    for (int k : table[i-1][j]) {
                        if (grid[i][j] == '(') {
                            int new_b = k+1;
                            if (new_b <= (rows+cols-1)/2) {
                                table[i][j].insert(new_b);
                            }
                        }
                        else if (k > 0) {
                            table[i][j].insert(k - 1);
                        }
                    }
               } 
               if (j != 0) {
                    for (int k : table[i][j-1]) {
                        if (grid[i][j] == '(') {
                            int new_b = k+1;
                            if (new_b <= (rows+cols-1)/2) {
                                table[i][j].insert(new_b);
                            }
                        }
                        else if (k > 0){
                            table[i][j].insert(k - 1);
                        }
                    }
               }
            }
        }
        bool fl = false;
        for (int k : table[rows-1][cols-1]) {
            if (k==0) {
                fl = true;
                break;
            }
        }
        return fl;
    }
};