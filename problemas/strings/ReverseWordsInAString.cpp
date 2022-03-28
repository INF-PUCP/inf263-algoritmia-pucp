// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) words.push_back(word);
        reverse(words.begin(), words.end());
        string sentence = "";
        int n_words = (int) words.size();
        for (int i = 0; i < n_words; i++) {
            if (i > 0) sentence += " ";
            sentence += words[i];
        }
        return sentence;
    }
};