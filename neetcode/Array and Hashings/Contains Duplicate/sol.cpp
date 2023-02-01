class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> exists;
        for(int num: nums) {
            if(exists[num]) return true;
            exists[num] = true;
        }
        return false;
    }
};