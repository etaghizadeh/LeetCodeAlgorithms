/* Follow up for N-Queens problem.
 
 Now, instead outputting board configurations, return the total number of distinct solutions.
 
 */

class Solution {
public:
    int totalNQueens(int n) {
        num = n;
        board = vector<vector<int> >(n, vector<int>(n, 0));
        return solveNQueens_it(0);
    }
private:
    int solveNQueens_it(int r)
    {
        if(r == num)
            return 1;
        int total = 0;
        for(int c=0; c<num; c++)
            if(board[r][c]==0)
            {
                placeQueenAt(r, c);
                int answers = solveNQueens_it(r+1);
                removeQueenFrom(r, c);
                total += answers;
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
};