public static void removeLeaves(Node node) {
        if (node == null)
            return;
        for (int i = node.children.size() - 1; i >= 0; i--) {
            if (node.children.get(i).children.size() == 0)
                node.children.remove(i);
            else
                removeLeaves(node.children.get(i));
        }
    }

// items can only be deleted from backward only from ArrayList<>(), if we are doing the del operation on the same list on which we are iterating.
// if we begin to delete from begining, then problem in iterators will be encountered, 
// error will be concurrent modification.
