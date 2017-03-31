/* Given an index k, return the kth row of the Pascal's triangle.
 
 For example, given k = 3,
 Return [1,3,3,1].
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre{1}, Result{1};
        for (int i=1; i<= rowIndex; i++)
        {
            Result[0] = 1;
            for(int j = 1; j < i; j++)
                Result[j] = pre[j-1] + pre[j];
            Result.insert(Result.end(), 1);
            
            pre = Result;
        }
        return Result;
    }
    
};