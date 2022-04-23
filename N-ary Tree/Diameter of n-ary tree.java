// PQ in java by defalut return min value.
// use new PriorityQueue<Integer>(Collections.reverseOrder()); to get max value on remove.

public class sol {
  public static class pair {
    int height, diameter;
  }

  public static pair dia(Node root) {
    pair p = new pair();
    if (root.children.size() == 0) {
      p.diameter = 0;
      p.height = 0;
      return p;
    }

    ArrayList<pair> al = new ArrayList<>();
    for (Node child : root.children) {
      pair temp = dia(child);
      al.add(temp);
    }

    int height_one = 0, height_two = 0;
    PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());

    for (pair it : al) {
      pq.add(it.height);
    }
    height_one = pq.remove();
    if (pq.size() != 0)
      height_two = pq.remove();

    pq = new PriorityQueue<Integer>(Collections.reverseOrder());

    int max_dia_of_childs = 0;
    for (pair it : al) {
      pq.add(it.diameter);
    }
    max_dia_of_childs = pq.remove();

    p.diameter = Math.max(height_one + height_two + 2, max_dia_of_childs);

    int height_of_root = height_one + 1;
    p.height = height_of_root;

    return p;
  }
}
