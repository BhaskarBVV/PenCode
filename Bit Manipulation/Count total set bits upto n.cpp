int countSetBits(int n)
    {
        if(n==1)
        return 1;
        if(n==0)
        return 0;
        int x = log(n)/log(2);
        // x=highest_pow_of_2_in_n
        // 0= 0     0     0     0
        // 1= 0     0     0     1
        // 2= 0     0     1     0
        // 3= 0     0     1     1
        // 4= 0     1     0     0
        // 5= 0     1     0     1
        // 6= 0     1     1     0
        // 7= 0     1     1     1  
        //    ^     ^     ^     ^
        //tot=     8/2 + 8/2 + 8/2 = 2^(x-1)*x = 2^(3-1) * 3 = 12
        //->>till now highest pow of 2=3 (i.e. 2^x=2^3=8)
        // so calculate the set bits before 8 by formula
        // 8= 1     0     0     0  
        // 9= 1     0     0     1
        //10= 1     0     1     0
        //    ^
        //    ^ add these bits(10-8+1 ->> n- 2^x + 1) to tot and do the same for rem numbers 
   
        // 9= 1     0     0     1
        //10= 1     0     1     0
        //          ^     ^     ^
        // after adding these 10-8+1 bits rem bits will be of form like numbers from 1 to 2
        // So we can easily calculate the total set bits upto any number with is power of n as (2^(x-1)*x)                                    
        int rem=n-pow(2,x); // These are the remaining numbers for which function will be called again.
        return pow(2,x-1)*x + n-pow(2,x)+1 + countSetBits(rem);
    }
