public static void mirror(Node node) {
        if (node == null)
            return;
        Collections.reverse(node.children);
        for (Node child : node.children) {
            mirror(child);
        }
    }
