/*  A robot is located at the top-left corner of a m x n grid.
 
 The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid.
 
 How many possible unique paths are there?
 
 
 Note: m and n will be at most 100.
 */



class Solution {
public:
    int uniquePaths(int m, int n) {
        int MAX = max(m, n);
        numPath = vector<vector<int> > (MAX+1, vector<int>(MAX+1, -1) );
        numPath[0][0] = 0;
        for(int i=1; i<MAX+1; i++)
        {
            numPath[i][1] = 1;
            numPath[i][0] = 0;
            numPath[1][i] = 1;
            numPath[0][i] = 0;
        }
        return iterate(m, n);
    }
private:
    vector<vector<int> > numPath;
    int iterate(int m, int n)
    {
        if(numPath[m][n] != -1)
            return numPath[m][n];
        int down = iterate(m-1, n);
        int right = iterate(m, n-1);
        int res = right + down;
        numPath[m][n] = res;
        numPath[n][m] = res;
        return res;
    }
};