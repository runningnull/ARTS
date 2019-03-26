/**
*    更优解：Manacher算法  
*/
class Solution {
    public String longestPalindrome(String s) {
        if (s.length() == 0) {
            return s;
        }
        int result = 0;
        int len = s.length();
        int sIndex = 0, eIndex = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j <= i && i+j < len; j++) {
                if (s.charAt(i-j) == s.charAt(i+j)) {
                    if (result < 2*j+1) {
                        result = 2*j+1;
                        sIndex = i-j;
                        eIndex = i+j;
                    }
                } else {
                    break;
                }
            }
            for (int j = 0; j <= i && i+j+1 < len; j++) {
                if (s.charAt(i-j) == s.charAt(i+j+1)) {
                    if (result < 2*j+2) {
                        result = 2*j+2;
                        sIndex = i-j;
                        eIndex = i+j+1;
                    }
                } else {
                    break;
                }
            }
        }
        return s.substring(sIndex, eIndex+1);
    }
}