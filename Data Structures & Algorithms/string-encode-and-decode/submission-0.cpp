class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (string s: strs) {
            int len = s.size();
            string size_s;
            while (len >=10) {
                size_s.insert(0, 1, len%10 + '0');
                len /= 10;
            }
            size_s.insert(0, 1, len%10 + '0');
            size_s.insert(0, 1, size_s.size() + '0');
            res.append(size_s);
            res.append(s);
        }

        return res;

    }

    vector<string> decode(string s) {
        vector<string> res;
        int start_index = 0;
        while (start_index < s.size()) {
            int len_size_s = s[start_index] - '0';
            int len = 0;
            int mul = 1;
            for (int i = start_index+len_size_s; i >start_index; i--) {
                len += mul * (s[i] - '0');
                mul *= 10;
            }
            res.push_back(s.substr(start_index+len_size_s+1, len));
            start_index += len_size_s+1+len;
        }

        return res;

    }
};
