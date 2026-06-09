class Solution {
public:
    bool checkIfExist(vector<vector<char>>& board, string word, int word_index, int row_index, int col_index,
                        int m, int n, set<vector<int>> &positions) {
        if (word_index == word.size())
            return true;
        for (int i = row_index - 1; i < row_index + 2; i++) {
            for (int j = col_index - 1; j < col_index + 2; j++) {
                if (positions.find({i,j}) != positions.end())
                    continue;
                if (i < 0 || j < 0 || i >= m || j >= n || (j != col_index && i != row_index))
                    continue;
                if (board[i][j] == word[word_index]) {
                    positions.insert({i,j});
                    if (checkIfExist(board, word, word_index+1, i, j, m, n, positions))
                        return true;
                    positions.erase(positions.find({i,j}));
                }
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> start_indices;
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j])
                    start_indices.push_back({i,j});
            }
        }
        for (int i = 0; i < start_indices.size(); i++) {
            set<vector<int>> positions;
            positions.insert(start_indices[i]);
            if (checkIfExist(board, word, 1, start_indices[i][0], start_indices[i][1], m, n, positions))
                return true;
        }
        return false;

        
    }
};
