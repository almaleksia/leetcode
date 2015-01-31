class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
           solve(board, 0);
    }
    
    bool solve(vector<vector<char> > &board, int cur_index) {
        if ( cur_index > 80 ) return true; 
        
        int row = cur_index / 9;
        int col = cur_index % 9;
        
        if ( board[row][col] != '.' ) {
            return solve(board, cur_index + 1);
        } 
        
        for ( int i = 1; i <= 9; i++ ) {
            board[row][col] = '0' + i;
            
            if ( validate_board(board, row, col) && solve(board, cur_index+1) ) {
                return true;   
            }
        }
        board[row][col] = '.';
        
        return false;
    }
    
    bool validate_board(vector<vector<char> > &board, int row, int col) {
        //check row
        int map_row[10] = {0};
        
        for ( int i = 0; i < 9; i++ ) {
                    if ( board[row][i] == '.' ) continue;
                    
                    int idx = board[row][i] - '0';
                    map_row[idx]++;
                    if ( map_row[idx] > 1 ) return false;
        }
        
        int map_col[10] = {0};
        
        // check col
       for ( int i = 0; i < 9; i++ ) {
            if ( board[i][col] == '.') continue;
                    
            int idx = board[i][col] - '0';
            map_col[idx]++;
            if ( map_col[idx] > 1 ) return false;
        }
        
        // check square
        int sqcol_begin = col - col % 3;
        int sqrow_begin = row - row % 3;
        
        int map_square[10] = {0};
        
        for ( int i = sqrow_begin; i <= sqrow_begin + 2; i++ ) {
            for ( int j = sqcol_begin; j <= sqcol_begin + 2; j++ ) {
                if ( board[i][j] == '.' ) continue;
                
                int idx = board[i][j] - '0';
                map_square[idx]++;
                
                if ( map_square[idx] > 1 ) return false;
            }
        }
        
        return true;
    }
};
