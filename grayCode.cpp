/*  The gray code is a binary numeral system where two successive values differ in only one bit.
 
 Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
 
 For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 
 00 - 0
 01 - 1
 11 - 3
 10 - 2
 
 Note:
 For a given n, a gray code sequence is not uniquely defined.
 
 For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 
 For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 */

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0)
            return vector<int>(1, 0);
        int num = pow2(n);
        vector<int> res(num, 0);
        for(int bit=0; bit<n; bit++)
        {
            int m = pow2(bit);
            while(m < num)
            {
                for(int i=m; i<m + pow2(bit+1) && i<num; i++)
                    setbit(res[i], bit);
                m = m + pow2(bit+2);
            }
        }
        return res;
    }
private:
    void setbit(int &num, int bit)
    {
        int i = (1 << bit);
        num |=  i;
    }
    int pow2(int n)
    {
        if(n == 0)
            return 1;
        return (2 << (n-1));
    }
};