// https://www.lintcode.com/problem/659/
class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        int number_of_strings = (int)strs.size();
        string encoding;
        for (int i = 0; i < number_of_strings; i++) {
            int size_of_string = (int)strs[i].size();
            encoding += to_string(size_of_string) + " " + strs[i];
        }
        return encoding;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        int size_of_encoding = (int)str.size();
        vector<string> strings;
        int start = 0;
        while (start < size_of_encoding) {
            int end = start;
            while (str[end] != ' ') {
                end++;
            }
            int size_of_string = stoi(str.substr(start, end - start));
            strings.push_back(str.substr(end + 1, size_of_string));
            start = end + size_of_string + 1;
        }
        return strings;
    }
};