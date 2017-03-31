/*   You are given an n x n 2D matrix representing an image.
 
 Rotate the image by 90 degrees (clockwise).
 
 Follow up:
 Could you do this in-place?
 */

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        
        int n = matrix.size();
        for(int i=0; n-i*2>1; i++)
        {
            int m = n - (i<<1) - 1;
            for(int j=0, l=i; j<m; j++, l++)
            {
                int p1 = matrix[l][n-i-1];
                matrix[l][n-i-1] = matrix[i][l];
                int p2 = matrix[n-i-1][n-l-1];
                matrix[n-i-1][n-l-1] = p1;
                p1 = matrix[n-l-1][i];
                matrix[n-l-1][i] = p2;
                matrix[i][l] = p1;
            }
        }
        
    }
};

