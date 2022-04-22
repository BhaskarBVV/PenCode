private static class Node {
      int data;
      ArrayList<Node> children = new ArrayList<>();
  }
  public static class pair {
      Node node;
      int state;

      pair(Node node, int state) {
          this.node = node;
          this.state = state;
      }
  }

  public static void IterativePreandPostOrder(Node node) {
      Stack<pair> st = new Stack<>();
      st.push(new pair(node, -1));
      ArrayList<Integer> pre = new ArrayList<>();
      ArrayList<Integer> post = new ArrayList<>();
      pair temp;
      while (!st.empty()) {
          temp = st.pop();
          if (temp.state == -1) {
              pre.add(temp.node.data);
              st.push(new pair(temp.node, temp.state + 1));
          } else if (temp.state == temp.node.children.size()) {
              post.add(temp.node.data);
          } else {
              st.push(new pair(temp.node, temp.state + 1));
              st.push(new pair(temp.node.children.get(temp.state), -1));

          }
      }
      System.out.println(pre);
      System.out.println(post);

  }

}
