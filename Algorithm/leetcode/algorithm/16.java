    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int result = nums[0] + nums[1] + nums[2];
        int len = nums.length;
        for (int i = 0; i < len - 2; i++) {
            int left = i + 1, right = len - 1;
            while (left < right) {
                int n = nums[i] + nums[left] + nums[right];
                int gap = n - target;
                if (gap == 0) {
                    return target;
                } else if (gap > 0) {
                    right--;
                } else {
                    left++;
                }
                if (Math.abs(result - target) > Math.abs(gap)) {
                    result = n;
                }
            }
        }
        return result;
    }