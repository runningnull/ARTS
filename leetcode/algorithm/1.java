class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        int len = nums.length;
        boolean flag = true;
        for (int i = 0; i < len-1 && flag; i++) {
            for (int j = i+1; j < len; j++) {
                if (nums[i] + nums[j] == target) {
                    result = new int[] {i, j};
                    flag = false;
                    break;
                }
            }
        }
        return result;
    }
}