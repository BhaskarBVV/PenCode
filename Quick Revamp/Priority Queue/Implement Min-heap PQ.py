class Solution:

    def initializeHeap(self):
        self.heap_list = []

    def __upheapify(self, index):
        if index == 0:
            return
        parent_index = (index-1)//2
        if self.heap_list[parent_index] > self.heap_list[index]:
            self.heap_list[parent_index], self.heap_list[index] = self.heap_list[index], self.heap_list[parent_index]
        self.__upheapify(parent_index)

    def insert(self, key):
        self.heap_list.append(key)
        # New value will be added at the end, and now we will keep on checking its value with its parents
        # until its parent value does not appears to be less than its child.
        self.__upheapify(len(self.heap_list)-1)

    def changeKey(self, index, new_val):
        if index >= len(self.heap_list):
            raise Exception("Index out of bound")
        self.heap_list[index] = new_val
        if index == 0:
            # We will sort the heap downward
            self.__downheapify(index)
            return
        if index == len(self.heap_list)-1:
            # We will sort the heap upward
            self.__upheapify(index)
            return
        parent_index = (index-1)//2

        # Now if the index is not 0 or last, we are un-sure in which direction we need to sort.
        # So, we will check if the index at which value is updated have its value smaller or greater than its parent.
        # If the parent value is more, means in min-heap the parent cannot hold min value, so we will sort upward.
        # else we'll sort downward...
        # Note: We haven't checked whether the index at which value is updated, have its both child values greater..
        # The __downheapify() method have already handled this for us.
        if self.heap_list[parent_index] > new_val:
            self.__upheapify(index)
        else:
            self.__downheapify(index)

    def __downheapify(self, index):
        mini = index
        heap_len = self.heapSize()

        # identify either of the left or right childs have value smaller than the current index.

        left_child_index = 2*index+1
        if left_child_index < heap_len and self.heap_list[mini] > self.heap_list[left_child_index]:
            mini = left_child_index
            # if left child exist and have smaller value, than update the mini variable

        right_child_index = 2*index+2
        if right_child_index < heap_len and self.heap_list[mini] > self.heap_list[right_child_index]:
            mini = right_child_index
            # if right child exist and have smaller value, than update the mini variable

        # Note in both the cases, we are not comparing with heap_list[index] instead we are doing with
        # heap_list[mini], because we have to identify the minimum value out of all 3
        # The parent, the left child and the right child.

        if mini != index:
            # if mini var is not equal to incoming index, means any one of the left or right have smaller value
            self.heap_list[index], self.heap_list[mini] = self.heap_list[mini], self.heap_list[index]
            # Swap the value and again downheapify the child index which is in mini
            self.__downheapify(mini)

    def extractMin(self):
        if len(self.heap_list) == 0:
            raise Exception("Heap is empty")
        heap_len = self.heapSize()

        last_index = heap_len-1
        # the min value will be at the top of the heap, that is at index 0.
        # And we can efficiently remove a value only from the last index..
        # S0, swap 0th and last index....
        self.heap_list[0], self.heap_list[last_index] = self.heap_list[last_index], self.heap_list[0]
        # Pop the last index, which is now having the smallest value.
        self.heap_list.pop()
        # After swap, the 0th index have larger value than its children, so sort the heap downward.
        self.__downheapify(0)

    def isEmpty(self):
        return len(self.heap_list) == 0

    def getMin(self):
        if self.heapSize() == 0:
            raise Exception("Queue is empty")
        return self.heap_list[0]

    def heapSize(self):
        return len(self.heap_list)
