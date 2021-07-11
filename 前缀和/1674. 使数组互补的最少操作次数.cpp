class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

    }
};
// type: 差分

/* tips */
/*
    a[i] + a[n - 1 - i] = x (2 <= x <= 2 * limit)
    suppose (a[i] + a[n - 1 - i]) == val;
    val == x : 0
    x - val <= max(limit - a[i], limit - a[n - 1 - i]) : 1
    val - x <= max(a[i] - 1, a[n - 1 - i] - 1) : 1
    other : 2 
*/

/* editorial */
/*
*/

/* question */
/*
*/