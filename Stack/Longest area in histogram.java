import java.util.*;

class Solution {
    class pair {
        int idx, val;

        pair(int x, int y) {
            val = x;
            idx = y;
        }
    }

    pair make_pair(int a, int b) {
        pair p = new pair(a, b);
        return p;
    }

    int[] nextSmLeft;
    int[] nextSmRght;

    void onleft(int[] a) {
        Stack<pair> st = new Stack<>();
        st.push(make_pair(a[0], 0));
        nextSmLeft[0] = -1;
        int k = 1;
        for (int i = 1; i < a.length; i++) {
            if (a[i] > st.peek().val) {
                nextSmLeft[k] = st.peek().idx;
                k++;
                st.push(make_pair(a[i], i));
            } else {
                while (!st.empty() && st.peek().val >= a[i])
                    st.pop();
                if (st.empty()) {
                    nextSmLeft[k] = -1;
                    k++;
                    st.push(make_pair(a[i], i));
                } else {
                    nextSmLeft[k] = st.peek().idx;
                    st.push(make_pair(a[i], i));
                    k++;
                }
            }
        }
    }

    void onright(int[] heights) {
        Stack<pair> st = new Stack<>();
        int n = heights.length;
        nextSmRght[n - 1] = n;
        int k = n - 2;
        st.push(make_pair(heights[n - 1], n - 1));
        for (int i = n - 2; i >= 0; i--) {
            if (st.peek().val < heights[i]) {
                nextSmRght[k] = st.peek().idx;
                k--;
                st.push(make_pair(heights[i], i));
            } else {
                while (!st.empty() && st.peek().val >= heights[i])
                    st.pop();
                if (st.empty()) {
                    nextSmRght[k] = n;
                    k--;
                    st.push(make_pair(heights[i], i));
                } else {
                    nextSmRght[k] = st.peek().idx;
                    k--;
                    st.push(make_pair(heights[i], i));
                }
            }
        }
    }

    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        nextSmLeft = new int[n];
        nextSmRght = new int[n];
        onleft(heights);
        onright(heights);

        int ans = Integer.MIN_VALUE, area;
        for (int i = 0; i < n; i++) {
            area = (nextSmRght[i] - nextSmLeft[i] - 1) * heights[i];
            if (area > ans)
                ans = area;
        }
        return ans;
    }
}
