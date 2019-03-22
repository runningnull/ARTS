import java.util.HashMap;
import java.util.Map;

/**
 * @author: linzj
 * date: 2019/3/22
 * time: 15:44
 * description: No Description
 */
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxCnt = 0;
        int lastIndex = 0;
        Map<Character, Integer> map = new HashMap<>(128);
        for (int i = 0; i < s.length(); i++) {
            Integer index = map.get(s.charAt(i));
            if (index != null && index > lastIndex) {
                lastIndex = index + 1;
            }
            int tmpCnt = i - lastIndex + 1;
            map.put(s.charAt(i), i);
            maxCnt = maxCnt > tmpCnt ? maxCnt : tmpCnt;
        }
        return maxCnt;
    }
//
//    public static void main(String[] args) {
//        new Solution().lengthOfLongestSubstring("abba");
//    }
}
