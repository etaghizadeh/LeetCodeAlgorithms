/*   Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 
 For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 
 Note:
 
 You must do this in-place without making a copy of the array.
 Minimize the total number of operations.
  */


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nZeros, n = nums.size(), copyHere = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0)
            {
                nZeros++;
                copyHere = i;
                break;
            }
        }
        if(nZeros==0)
            return;
        for(int i=copyHere; i<n; i++)
        {
            if(nums[i]==0)
                continue;
            nums[copyHere++] = nums[i];
        }
        for(int i=copyHere; i<n; nums[i++]=0);
    }
    
};