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
        // since the left most value cannot have any value smaller than it, hence next smaller for it will be -1;
        ans[0] = -1;
        st.push(a[0]);
        // push that value in stack, this value can be next smaller on left for incoming values.
        int k = 1;
        // start taking values from index 1;
        // there will be three cases:
        // 1) either the value on top of stack will be smaller than current element a[i], 
        //    in this case the next smaller on left for this a[i] will be stack.top()
        //    and push current a[i] in stack, because this value may become next smaller for next coming values.
        //          ex-> 1 2 3 , here even if 1 is Nxt smlr on lft for 2, but even then we push 2, bcz now 2 will be nxt smlr for 3.
        // 2) either the value on top of stack is equal or larger than current value a[i],
        //    in this case, pop from stack until stack is empty or value on top is less than current a[i].
        //    a) if stack becomes empty, then we can say there is no value in array on left of current value that is smaller than it.
        //       hence, next samller on left for it will be -1 and also push this current a[i] in stack.
        //    b) if stack does not get empty, but some value on top of stack is less than current, then stack.peek() will be the next smaller on left for current a[i]
        //       also, push currrent a[i] in stack  
        for (int i = 1; i < n; i++) {
            if (a[i] > st.peek()) {
                ans[k] = st.peek();
                k++;
                st.push(a[i]);
            } else {
                while (!st.empty() && st.peek() >= a[i])
                    st.pop();
                if (st.empty()) {
                    ans[k] = -1;
                    k++;
                    st.push(a[i]);
                } else {
                    ans[k] = st.peek();
                    k++;
                    st.push(a[i]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.println(a[i] + " " + ans[i]);
        }
    }
}
