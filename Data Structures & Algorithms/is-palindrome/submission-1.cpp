class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        for (int i =0 ; i< len; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] - 'A' + 'a';
            if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) {
                s.erase(i, 1);
                i--;
                len--;
            }

        }

        for (int i = 0; i < len / 2; i++)
            if (s[i] != s[len -i - 1])
                return false;

        return true;
        
    }
};
