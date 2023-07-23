class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> results = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            // Skip duplicates of the current element to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = -nums[i];
            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    // Triplet found, add it to the results list
                    results.add(Arrays.asList(nums[i], nums[left], nums[right]));

                    // Skip duplicates of left and right elements to avoid duplicate triplets
                    while (left + 1 < right && nums[left] == nums[left + 1])
                        left++;
                    while (right - 1 > left && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                } else if (sum > target) {
                    // If sum is greater than the target, decrease right pointer
                    right--;
                } else {
                    // If sum is less than the target, increase left pointer
                    left++;
                }
            }
        }

        return results;
    }
}
