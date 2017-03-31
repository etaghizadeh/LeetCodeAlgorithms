/*  Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
 
 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        bool No0 = 1;
        int N = 1, Bit_N = 1, n = nums.size();
        int result = 0;
        while(No0 && N<=32)
        {   No0 = 0;
            int counter = 0;
            for(int i=0; i<n; i++)
            {
                counter+= nums[i]&1;
                nums[i] = nums[i]>>1;
                if(nums[i])
                    No0 = 1;
            }
            counter = counter%3;
            if(counter)
                result = result | Bit_N;
            Bit_N = Bit_N << 1;
            N++;
        }
        return result;
    }
};
