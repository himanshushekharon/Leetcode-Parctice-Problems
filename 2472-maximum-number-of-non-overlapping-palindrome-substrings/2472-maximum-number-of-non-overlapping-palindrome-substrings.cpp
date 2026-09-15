class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int count = 0;
        int last_end = -1; // Keeps track of the end index of the last chosen palindrome

        // We can check all centers (both single characters and gaps between characters)
        for (int center = 0; center < 2 * n - 1; ++center) {
            int left = center / 2;
            int right = left + center % 2;

            // Expand around center to find palindromes
            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len >= k) {
                    // If this palindrome doesn't overlap with the last chosen one
                    if (left > last_end) {
                        count++;
                        last_end = right;
                        break; // Greedily pick this and move on to find the next
                    }
                }
                left--;
                right++;
            }
        }
        return count;
    }
};