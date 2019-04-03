class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        int[] nums = new int[20];
        int index = 0;
        while (x > 0) {
            nums[index++] = x % 10;
            x /= 10;
        }
        for (int i = 0; i < index/2; i++) {
            if (nums[i] != nums[index-i-1]) {
                return false;
            }
        }
        return true;
    }
}