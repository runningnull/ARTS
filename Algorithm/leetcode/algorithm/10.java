class Solution {
    public int maxArea(int[] height) {
        int result = 0;
        int len = height.length;
        for (int i = 0; i < len; i++) {
            for (int j = len-1; j > i; j--) {
                result = Math.max(result, (j-i)*Math.min(height[i], height[j]));
            }
        }
        return result;
    }

    public int maxArea(int[] height) {
        int result = 0;
        int left = 0, right = height.length-1;
        while (left < right) {
            result = Math.max(Math.min(height[left], height[right]) * (right - left), result);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
}