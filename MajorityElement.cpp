/*   Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 
 You may assume that the array is non-empty and the majority element always exist in the array.
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj, count = 0, sz_ = nums.size();
        for(int i=0; i<sz_; i++)
        {
            if(count == 0)
            {
                maj = nums[i];
                count = 1;
            }
            else
                if(maj == nums[i])
                {
                    count++;
                    if (count > (sz_ >> 1) )
                        return maj;
                }
                else count--;
        }
        return maj;
    }
    
};