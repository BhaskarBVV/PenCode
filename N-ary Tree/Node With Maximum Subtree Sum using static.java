public static int max_sum, max_node;

    public static int treeHelper(Node node) {
        int sum = node.data;
        for (Node child : node.children) {
            sum += treeHelper(child);
        }
        if (sum > max_sum) {
            max_sum = sum;
            max_node = node.data;
        }
        return sum;
    }

    public static void main(String[] args) throws Exception {
        //----- code....
        //----- code.... 
        max_sum = -1;
        max_node = -1;
        Node root = construct(arr);
        int ans = treeHelper(root);
        System.out.println(max_node + "@" + max_sum);
    }
