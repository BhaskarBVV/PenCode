 public static int height(Node node) {
        if (node == null)
            return -1;
   
        int ht = -1;
   
        for (Node child : node.children) {
            ht= Math.max(ht, height(child));
        }
        return ht+1;
    }
