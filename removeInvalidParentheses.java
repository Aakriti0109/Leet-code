class Solution {
    Set<String> ans = new HashSet<>();

    public List<String> removeInvalidParentheses(String s) {
        Stack<Character> st = new Stack<>();
        int l = 0, r = 0;

        for (char c : s.toCharArray()) {
            if (c == '(') st.push(c);
            else if (c == ')') {
                if (!st.empty()) st.pop();
                else r++;
            }
        }

        l = st.size();
        solve(s, 0, l, r);
        return new ArrayList<>(ans);
    }

    void solve(String s, int start, int l, int r) {
        if (l == 0 && r == 0) {
            if (valid(s)) ans.add(s);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            if (i > start && s.charAt(i) == s.charAt(i - 1)) continue;

            char c = s.charAt(i);

            if (c == '(' && l > 0)
                solve(s.substring(0, i) + s.substring(i + 1), i, l - 1, r);

            if (c == ')' && r > 0)
                solve(s.substring(0, i) + s.substring(i + 1), i, l, r - 1);
        }
    }

    boolean valid(String s) {
        Stack<Character> st = new Stack<>();

        for (char c : s.toCharArray()) {
            if (c == '(') st.push(c);
            else if (c == ')' && (st.empty() || st.pop() != '('))
                return false;
        }

        return st.empty();
    }
}