public static ArrayList<Integer> nodeToRootPath(Node node, int data) {
        if (node == null)
            return new ArrayList<>();

        if (node.data == data) {
            ArrayList<Integer> al = new ArrayList<>();
            al.add(node.data);
            return al;
        }
        for (Node child : node.children) {
            ArrayList<Integer> getList = nodeToRootPath(child, data);
            if (getList.size() > 0) {
                getList.add(node.data);
                return getList;
            }
        }
        return new ArrayList<>();
    }

    public static int lca(Node node, int d1, int d2) {
        ArrayList<Integer> al_d1 = nodeToRootPath(node, d1);
        ArrayList<Integer> al_d2 = nodeToRootPath(node, d2);
        int lca = -1;
        int i = al_d1.size() - 1, j = al_d2.size() - 1;
        while (i >= 0 && j >= 0) {
            if (al_d1.get(i) != al_d2.get(j))
                break;
            lca = al_d1.get(i);
            i--;
            j--;
        }
        return lca;
    }
