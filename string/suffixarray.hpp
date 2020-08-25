/**
* @brief 接尾辞配列 (Suffix Array)
* @docs docs/string/suffixarray.md
*/

struct SuffixArray {
    vector<int> sa;
    string s;
    SuffixArray(string &s)
        : s(s) {
        sa.resize(s.size());
        iota(begin(sa), end(sa), 0);
        sort(begin(sa), end(sa), [&](int a, int b) {
            return (s[a] == s[b]) ? a > b : s[a] < s[b];
        });
        vector<int> cls(s.size()), c(s.begin(), s.end()), cnt(s.size());
        for (int l = 1; l < s.size(); l <<= 1) {
            for (int i = 0; i < s.size(); i++) {
                if (i > 0 and c[sa[i - 1]] == c[sa[i]] and sa[i - 1] + l < s.size() and c[sa[i - 1] + l / 2] == c[sa[i] + l / 2]) {
                    cls[sa[i]] = cls[sa[i - 1]];
                } else {
                    cls[sa[i]] = i;
                }
            }
            iota(begin(cnt), end(cnt), 0);
            copy(begin(sa), end(sa), begin(c));
            for (int i = 0; i < s.size(); i++) {
                int s1 = c[i] - l;
                if (s1 >= 0) sa[cnt[cls[s1]]++] = s1;
            }
            cls.swap(c);
        }
    }
    bool lt_substr(const string &t, int si = 0, int ti = 0) {
        int sn = (int)s.size(), tn = (int)t.size();
        while (si < sn and ti < tn) {
            if (s[si] < t[ti]) return true;
            if (s[si] > t[ti]) return false;
            ++si, ++ti;
        }
        return si >= sn and ti < tn;
    }
    int lower_bound(const string &t) {
        int low = -1, high = (int)sa.size();
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (lt_substr(t, sa[mid]))
                low = mid;
            else
                high = mid;
        }
        return high;
    }
    pair<int, int> lower_upper_bound(string &t) {
        int idx = lower_bound(t);
        int low = idx - 1, high = (int)sa.size();
        t.back()++;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (lt_substr(t, sa[mid]))
                low = mid;
            else
                high = mid;
        }
        --t.back();
        return make_pair(idx, high);
    }
    void print() {
        for (int i = 0; i < sa.size(); ++i) {
            cerr << i << " : " << s.substr(sa[i]) << endl;
        }
    }
};
