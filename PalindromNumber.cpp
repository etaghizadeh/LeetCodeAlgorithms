/*   Determine whether an integer is a palindrome. Do this without extra space. */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long long int i = 10;
        for(; i<x; i*=10);
        i/=10;
        while(x>9)
        {
            if (x%10 != x/i)
                return false;
            x = (x%i)/10;
            i = i/100;
        }
        return (i<10 || !x);
    }
    
};