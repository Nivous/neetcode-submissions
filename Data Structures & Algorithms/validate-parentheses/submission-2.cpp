class Solution {
public:
    bool isOpen(char c) {
        return c== '(' || c== '[' || c== '{';
    }
    char findOpposite(char c) {
        switch (c) {
            case '(': return ')';
            case ')': return '(';
            case '[': return ']';
            case ']': return '[';
            case '{': return '}';
            case '}': return '{';
            default: return 'x';
        }
    }
    bool isValid(string s) {
        stack<char> open;
        for (int i = 0;i < s.size(); i++) {
            if (isOpen(s[i]))
                open.push(s[i]);
            else {
                if (open.empty() || open.top() != findOpposite(s[i]))
                    return false;
                open.pop();
            }
        }

        return open.empty();
    }
};
