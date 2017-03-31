/*   Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 
 Try to solve it in linear time/space.
 
 Return 0 if the array contains less than 2 elements.
 
 You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 */

class Solution {
public:
    int maximumGap(vector<int> &num) {
        n = num.size();
        if(n<2)
            return 0;
        for(int i=0; i<4;i++)
            radixSort(num, i);
        int maxGap = 0;
        for(int i=0; ++i<n;)
        {
            int diff = num[i] - num[i-1];
            if(maxGap < diff)
                maxGap = diff;
        }
        return maxGap;
    }
private:
    int n;
    void radixSort(vector<int> &num, int rank)
    {
        vector<int> counter(257, 0);
        int x = 0xFF;
        for(int i=0; i<n; i++)
            counter[(x & (num[i] >> rank*8))+1]++;
        if(counter[1]==n)
            return;
        for(int i=1; i<257; i++)
            counter[i] += counter[i-1];
        vector<int> temp(n);
        for(int i=0; i<n; i++)
            temp[counter[x & (num[i] >> rank*8 )]++] = num[i];
        for(int i=0; i<n; i++)
            num[i] = temp[i];
    }
};
