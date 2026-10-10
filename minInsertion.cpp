
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int i = 0, result = 0, count = 0;

        while (i < n) {
            if (s[i] == '(') {
                count++;
                i++;
            } else {
                if (count > 0) {   
                    count--;
                } else {  //count = 0 on a ')' means there was no '(' existed.          
                  result++; // add '('
                }

                if (i + 1 < n && s[i + 1] == ')') {
                    i += 2;
                } else {
                    result++; // add ')'
                    i++;
                }
            }
        }

        return result + count * 2;
    }
};