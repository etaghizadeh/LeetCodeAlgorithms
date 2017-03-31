/*   Given two strings s and t, write a function to determine if t is an anagram of s.
 
 For example,
 s = "anagram", t = "nagaram", return true.
 s = "rat", t = "car", return false.
 
 Note:
 You may assume the string contains only lowercase alphabets.
 
 Follow up:
 What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        int ns = s.size();
        if (ns!=t.size()) return false;
        vector<int> counter(26);
        for (int i=0; i<ns; i++)
        {
            ++counter[s[i]-'a'];
            --counter[t[i]-'a'];
        }
        for(int i=0; i<26; i++)
        {
            if(counter[i]!=0)
                return false;
        }
        return true;
    }
    
};