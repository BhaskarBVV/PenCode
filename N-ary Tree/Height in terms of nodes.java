public int maxDepth(Node node) {
        if (node == null)
            return 0;
  
        int ht = 0;
  
        for (Node child : node.children) {
            ht= Math.max(ht, maxDepth(child));
        }
        return ht+1;
    }
