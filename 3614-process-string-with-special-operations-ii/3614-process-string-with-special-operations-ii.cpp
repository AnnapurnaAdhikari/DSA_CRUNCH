class Solution {
public:
    char processStr(string s, long long k) {
        const long long INF = (long long)4e18;

        int n = s.size();
        vector<long long> pref(n);

        long long len = 0;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (islower(c)) {
                len++;
            }
            else if (c == '*') {
                if (len > 0) len--;
            }
            else if (c == '#') {
                len = min(INF, len * 2);
            }
            // '%'
            // length unchanged

            pref[i] = len;
        }

        if (k >= len)
            return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            long long cur = pref[i];
            long long prev = (i ? pref[i - 1] : 0);

            if (islower(c)) {
                if (k == cur - 1)
                    return c;
            }
            else if (c == '#') {
                long long old = prev;
                if (old > 0)
                    k %= old;
            }
            else if (c == '%') {
                if (cur > 0)
                    k = cur - 1 - k;
            }
            // '*' needs no change

            len = prev;
        }

        return '.';
    }
};