class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = (int)arr.size();
        vector<int> s(n + 1, 0);
        for (int k = 1; k <= n; ++k) s[k] = s[k - 1] ^ arr[k - 1];
        int res = 0; map<int, int> hash;
        for (int i = 1; i <= n - 1; ++i) {
            for (int k = i + 1; k <= n; ++k) 
            if (0 == (s[k] ^ s[i - 1])) res += k - i;
        }
        return res;
    }
};
// type: partial-sum idea

/* tips */
/*
*/

/* editorial */
/*
*/

/* question */
/*
    hash method?
*/