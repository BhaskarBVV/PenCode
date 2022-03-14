import java.util.*;

public class JavaEditor1 {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        Stack<Integer> st = new Stack<>();
        int[] ans = new int[n];
        ans[n - 1] = -1;
        int k = n - 2;
        st.push(a[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            if (st.peek() < a[i]) {
                ans[k] = st.peek();
                k--;
                st.push(a[i]);
            } else {
                while (!st.empty() && st.peek() >= a[i])
                    st.pop();
                if (st.empty()) {
                    ans[k] = -1;
                    k--;
                    st.push(a[i]);
                } else {
                    ans[k] = st.peek();
                    k--;
                    st.push(a[i]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.println(a[i] + " " + ans[i]);
        }
    }
}
