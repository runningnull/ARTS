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