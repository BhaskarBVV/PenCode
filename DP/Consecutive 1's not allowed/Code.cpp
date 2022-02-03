ll countStrings(int n) {
    	int oldOne = 1, oldZero = 1, nZero, nOne;
        for (int i = 1; i < n; i++)
        {
            nOne = oldZero;
            nZero = (oldOne + oldZero) % (1000000007);
    
            oldOne = nOne;
            oldZero = nZero;
        }
        return (oldOne + oldZero) % (1000000007);
	}
