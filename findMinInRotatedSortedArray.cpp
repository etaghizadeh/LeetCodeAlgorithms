/*  Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 
 Find the minimum element.
 
 You may assume no duplicate exists in the array.
 */



class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size()-1);
    }
private:
    int findMin(vector<int> &num, int lo, int hi)
    {
        if(lo>=hi)
            return num[hi];
        int Mid = lo + (hi-lo)/2;
        if(num[Mid] <= num[Mid-1] && num[Mid] <= num[Mid+1])
            return num[Mid];
        if(num[lo] < num[hi])
            return num[lo];
        if(num[Mid] < num[lo])
            return findMin(num, lo, Mid-1);
        return findMin(num, Mid+1, hi);
    }
};
