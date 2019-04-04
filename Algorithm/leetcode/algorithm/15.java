import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int len = nums.length;
        List<List<Integer>> result = new ArrayList<>();
        if (len < 3) {
            return result;
        }

        Arrays.sort(nums);
        Set<String> set = new HashSet<>();
        for (int i = 0; i < len - 2; i++) {
            for (int j = i + 1; j < len - 1; j++) {
                if (!set.contains("" + nums[i] + nums[j])) {
                    set.add("" + nums[i] + nums[j]);
                    for (int k = j + 1; k < len; k++) {
                        if (nums[i] + nums[j] + nums[k] == 0) {
                            result.add(Arrays.asList(nums[i], nums[j], nums[k]));
                            break;
                        }
                    }
                }
            }
        }
        return result;
    }

    public List<List<Integer>> threeSum(int[] nums) {
        int len = nums.length;
        List<List<Integer>> result = new ArrayList<>();
        if (len < 3) {
            return result;
        }
        Arrays.sort(nums);

        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < len - 1; j++) {
                int tmp = -1 * (nums[i] + nums[j]);
                boolean existed = tmp < nums[j + 1] || (nums[j] == nums[j - 1] && j >= i + 2);
                if (existed) {
                    continue;
                }
                int left = j + 1, right = len - 1;
                while (left <= right) {
                    int mid = (left + right) >> 1;
                    if (tmp == nums[mid]) {
                        result.add(Arrays.asList(nums[i], nums[j], tmp));
                        break;
                    }
                    if (tmp < nums[mid]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
        }
        return result;
    }

    public List<List<Integer>> threeSum(int[] nums) {
        int len = nums.length;
        if (len < 3) {
            return Collections.EMPTY_LIST;
        }
        Arrays.sort(nums);
        if (nums[0] > 0 || nums[len - 1] < 0) {
            return Collections.EMPTY_LIST;
        }
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = len - 1, target;
            while (left < right) {
                target = nums[i] + nums[left] + nums[right];
                if (target == 0) {
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    while (left + 1 < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (right - 1 > left && nums[right] == nums[right - 1]) {
                        right--;
                    }
                } else if (target < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
}