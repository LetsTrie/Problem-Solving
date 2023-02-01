class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> lastOccurance;
        vector <int> response;
        int length = nums.size();

        for (int index = 0; index < length; index++) {
            int number = nums[index];
            int difference = target - number;

            if(lastOccurance.find(difference) != lastOccurance.end()) {
                response.push_back(index);
                response.push_back(lastOccurance[difference]);
                break;
            }

            lastOccurance[number] = index;
        }

        return response;
    }
};