/*   Given a column title as appear in an Excel sheet, return its corresponding column number.
 
 For example:
 
 A -> 1
 B -> 2
 C -> 3
 ...
 Z -> 26
 AA -> 27
 AB -> 28
  */


class Solution {
public:
    int titleToNumber(string s) {
        int n = 0, l = s.length();
        for(int i=0; i < l; i++)
            n = n*26 + s[i] - 'A' + 1;
        return n;
    }
    
};