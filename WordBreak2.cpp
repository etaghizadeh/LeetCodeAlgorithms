/*    Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.
 
 Return all such possible sentences.
 
 For example, given
 s = "catsanddog",
 dict = ["cat", "cats", "and", "sand", "dog"].
 
 A solution is ["cats and dog", "cat sand dog"].
 
 */

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> Result;
        int size = s.size();
        if (!size)
            return Result;
        if(dict.find(s) != dict.end())
            Result.insert(Result.begin(), s);
        for(int i = size-1; i>0; i--)
        {
            string S1 = s.substr(0, i), S2 = s.substr(i, size-i);
            if (dict.find(S2) != dict.end())
            {
                vector<string> v = wordBreak(S1, dict);
                for(string j:v)
                {
                    string str = j + " " + S2;
                    Result.insert(Result.end(), str );
                }
            }
            
        }
        return Result;
    }
};