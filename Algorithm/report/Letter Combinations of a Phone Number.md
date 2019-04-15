## LeetCode  17. Letter Combinations of a Phone Number 解题报告 

[题目链接](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)  

#### 题目意思  
用老手机的九宫格，按一些数字键，要求输出按这些键所有可能出现的字符串。  

例子：  
Input: "23"  
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].  

#### 解题过程  
题目就是求解位置固定的所有字母组合情况，而且输出的结果是按字典序升序输出的。  
所以要么整理一堆循环遍历出来，要么用深搜遍历出来。显而易见深搜的写法更简单。但是如果输入的数字键位数过长的话，深搜容易导致栈溢出，那么就要用循环遍历来怼。  
```java
String[] maps = new String[]{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
List<String> result;

private void DFS(String digits, int index, String tmp) {
    if (index == digits.length()) {
        result.add(tmp);
        return;
    }
    int pos = digits.charAt(index) - '2';
    for (int i = 0; i < maps[pos].length(); i++) {
        String tmpString = tmp;
        tmp += maps[pos].charAt(i);
        DFS(digits, index + 1, tmp);
        tmp = tmpString;
    }
}

public List<String> letterCombinations(String digits) {
    result = new ArrayList<>();
    if (digits.length() == 0) {
        return result;
    }
    DFS(digits, 0, "");
    return result;
}
```