class Solution {
private:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

public:
    bool halvesAreAlike(string s) {
        int vowelsFirstHalf = 0, vowelsSecondHalf = 0;
        for (int i = 0; i < s.length() / 2; i++) {
            if (isVowel(s[i]))
                vowelsFirstHalf++;
            if (isVowel(s[i + s.length() / 2]))
                vowelsSecondHalf++;
        }

        return vowelsFirstHalf == vowelsSecondHalf;
    }
};