int order = 0;
    for (int i = 0; i < input1.length() - 1; i++) {
        if (input1.charAt(i) < input1.charAt(i + 1) && input1.charAt(0) < input1.charAt(input1.length() - 1))
            order = 1; //Increasing
        else if (input1.charAt(i) > input1.charAt(i + 1) && input1.charAt(0) > input1.charAt(input1.length() - 1))
            order = 2; //Decreasing
        else
            return "Not in any Order";
    }
