## LeetCode 15.ThreeSum 解题报告  

[题目链接](https://leetcode-cn.com/problems/3sum/)  

#### 题目意思  
给定一个整型数组，求数组中元素 a, b, c 满足 a + b + c = 0 的所有组合。输出符合条件的[a, b, c] 组合，并且重复组合只输出一次。  

Given array nums = [-1, 0, 1, 2, -1, -4],  

A solution set is:  
[  
  [-1, 0, 1],  
  [-1, -1, 2]  
]  

#### 解题过程  
看到这个题目时，下意识就会想用暴力求解，即先将数组进行升序排序，然后用 3 层嵌套遍历求出所有可能的组合，并且用 Set 集合对组合的元素进行去重。  

```java
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
```

虽然上面代码可以求出正确的结果，但是时间复杂度已经是 O(n^3), 这是无法容忍的，而且一向以宽容著称的 LeetCode 也给出了 <font color=red>Time Limit Exceeded </font> ，既然是超时，那么我的初步优化想法是将算法复杂度尽量从 O(n^3) 降到 O(n^2)，考虑到因为数组已经排序过了，在有序数组中查询元素的常用时间复杂度较低的算法就是二分了。所以<font color=#C8B915>我将上面代码的 3 层嵌套查询优化为了 2 层嵌套查询+1 次二分查询。另外不在使用 Set 集合进行去重，而是直接进行逻辑判断去重，因为 Set 的 contains 方法也是线性查找的，另外字符串拼接十分耗费时间和空间</font>  

```java
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
            while (left <= right) { //二分查询
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
```

值得高兴的是，上面代码通过了测试，耗时 151 ms ，这个运行时间在所有 Java 提交记录中，排名倒数20%，所以我们的代码还是有很大的改进空间。因为我们上面的代码时间复杂度还是 O(n^2 * logn) 并没有真正达到 O(n^2)。后来看到一个评论说定义三个指针，然后将三数之和转化为两数之和 nums[i] = nums[j] + nums[k]。nums[j] + nums[k] 可以用两个指针分别从左右两边向中间扫描，这样的时间复杂度就是 O(n) ，而总共的最坏时间复杂度就是 O(n^2) 。  

以下就是优化后的解法：  

```java
public List<List<Integer>> threeSum(int[] nums) {
    int len = nums.length;
    if (len < 3) {
        return Collections.EMPTY_LIST;
    }
    Arrays.sort(nums);
    if (nums[0] > 0 || nums[len - 1] < 0) { //对于一定不存在结果的数组进行特判
        return Collections.EMPTY_LIST;
    }
    List<List<Integer>> result = new ArrayList<>();
    for (int i = 0; i < len - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int left = i + 1, right = len - 1; //定义左右两个扫描指针
        int target;
        while (left < right) {
            target = nums[i] + nums[left] + nums[right];
            if (target == 0) {
                result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                while (left + 1 < right && nums[left] == nums[left - 1]) {
                    left++; //判重
                }
                while (right - 1 > left && nums[right] == nums[right - 1]) {
                    right--; //判重
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
```
