/*   The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 
 Given an integer n, return all distinct solutions to the n-queens puzzle.
 
 Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 
 For example,
 There exist two distinct solutions to the 4-queens puzzle:
 
 [
 [".Q..",  // Solution 1
 "...Q",
 "Q...",
 "..Q."],
 
 ["..Q.",  // Solution 2
 "Q...",
 "...Q",
 ".Q.."]
 ]

 
 */

class Solution {
public:
    vector<vector<string> > solveNQueens(int n){
        num = n;
        board = vector<vector<int> >(n, vector<int>(n, 0));
        solveNQueens_it(0);
        return result;
    }
private:
    int solveNQueens_it(int r)
    {
        if(r == num)
        {
            string str(num, '.');
            result.insert(result.end(), vector<string>(num, str));
            return 1;
        }
        int total = 0;
        for(int c=0; c<num; c++)
        {
            if(board[r][c]==0)
            {
                placeQueenAt(r, c);
                int answers = solveNQueens_it(r+1);
                int no = result.size() - 1;
                for(int a=0; a < answers; a++)
                    result[no - a][r][c] = 'Q';
                removeQueenFrom(r, c);
                total += answers;
            }
        }
        return total;
    }
    
    void placeQueenAt(int r, int c)
    {
        board[r][c] = 1;
        for(int i=r+1; i<num; i++)
        {
            board[i][c]++;
            if(c-r+i < num )
                board[i][c-r+i]++;
            if(r+c-i >= 0)
                board[i][r+c-i]++;
        }
    }
    void removeQueenFrom(int r, int c)
    {
        if(board[r][c] == 0)
            return;
        for(int i=r+1; i<num; i++)
        {
            board[i][c]--;
            if(c-r+i < num && c-r+i >= 0 )
                board[i][c-r+i]--;
            if(r+c-i >= 0)
                board[i][r+c-i]--;
        }
        board[r][c] = 0;
    }
    int num;
    vector<vector<int> > board;
    vector<vector<string> > result;
    
};