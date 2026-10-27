class Solution {
    public boolean isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

    public boolean halvesAreAlike(String s) {
        int n = s.length();
        int mid = n / 2;

        int i = 0;
        int j = mid;

        int v1 = 0;
        int v2 = 0;

        while (i < mid && j < n) {
            if (isVowel(s.charAt(i))) {
                v1++;
            }

            if (isVowel(s.charAt(j))) {
                v2++;
            }

            i++;
            j++;
        }

        return v1 == v2;
    }
}