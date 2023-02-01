class Solution {
public:
    bool isAnagram(string s, string t) {
        int charMapping[26] = {0};

        for(auto const &ch: s) charMapping[ch - 'a']++;
        for(auto const &ch: t) charMapping[ch - 'a']--;

        for(int index = 0; index < 26; index++) {
            if(charMapping[index] != 0) return false;
        }
        return true;
    }
};