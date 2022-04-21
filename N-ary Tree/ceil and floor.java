static int ceil;
    static int floor;

    public static void ceilAndFloor(Node node, int data) {
        if (node.data < data) {
            if (floor < node.data)
                floor = node.data;
        } else if (node.data > data) {
            if (ceil > node.data)
                ceil = node.data;
        }
        for (Node child : node.children) {
            ceilAndFloor(child, data);
        }
    }


// ceil : data se just badi value (matlab data se jo saari badi values hain, unmein se sabse choti value)
// floor: data se just choti value (matlab data se jo saari choti values hain, unmein se sabse badi value)
