// https://leetcode.com/problems/sliding-window-maximum/description/

public class Solution {
    public int[] MaxSlidingWindow(int[] nums, int k) {
        // This deque will store indexes of useful elements in the current window
        var dequeue = new LinkedList<int>();
        int j = 0;
        var ans = new List<int>();

        // Process the first window of size k
        while (j < k) {
            // Remove elements from the back if they are smaller than the current element
            // because they cannot be the maximum if a larger element exists
            while (dequeue.Count > 0 && nums[dequeue.Last.Value] <= nums[j]) {
                dequeue.RemoveLast();
            }
            // Add current index to the deque
            dequeue.AddLast(j);
            j += 1;
        }

        // Process the rest of the elements
        while (j < nums.Length) {
            // The front of the deque contains the index of the maximum element for the previous window
            ans.Add(nums[dequeue.First.Value]);

            // Remove all elements smaller than the current element from the back
            while (dequeue.Count > 0 && nums[dequeue.Last.Value] <= nums[j]) {
                dequeue.RemoveLast();
            }

            // Add current index
            dequeue.AddLast(j);

            // Remove indices from the front if they are out of the current window
            while (dequeue.Count > 0 && dequeue.First.Value <= j - k) {
                dequeue.RemoveFirst();
            }

            j += 1;
        }

        // Add the maximum for the last window
        ans.Add(nums[dequeue.First.Value]);

        return ans.ToArray();
    }
}
