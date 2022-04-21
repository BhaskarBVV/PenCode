public static boolean areMirror(Node n1, Node n2) {
        if (n1.children.size() != n2.children.size())
            return false;
        for (int i = 0, j = n1.children.size() - 1; i < n1.children.size() && j >= 0; i++, j--) {
            if (!areMirror(n1.children.get(i), n2.children.get(j)))
                return false;
        }
        return true;
    }
