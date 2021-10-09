// Reverse first d elements in the array starting from the first index.
// Reverse the next (n-d) elements left in the array.
// Reverse the whole array.

void rotateArr(int a[], int d, int n){
        d=d%n;
        reverse(a,a+d);
        reverse(a+d,a+n);
        reverse(a,a+n);
        
    }
