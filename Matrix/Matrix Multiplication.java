import java.util.Scanner;

public class editor {
    public static Scanner sc = new Scanner(System.in);

    public static void input(int[][] A) {
        System.out.println("Enter the matrix\n");
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[0].length; j++) {
                A[i][j] = sc.nextInt();
            }
        }
    }

    public static int[][] matrix_mul(int[][] A, int[][] B) {
        int n1 = A.length, m1 = A[0].length, n2 = B.length, m2 = B[0].length;
        int[][] res = new int[n1][m2];
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m2; j++) {
                int sum = 0;
                for (int k = 0; k < m1; k++) {
                    sum += A[i][k] * B[k][j];
                }
                res[i][j] = sum;
            }
        }
        return res;
    }

    public static void display(int[][] A) {
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[0].length; j++) {
                System.out.print(A[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String args[]) {

        System.out.println("Enter the row and columns of matrix 1");
        int n1 = sc.nextInt();
        int m1 = sc.nextInt();
        int[][] arr = new int[n1][m1];
        input(arr);
        System.out.println("Matrix 1: ");
        display(arr);
      
        System.out.println("Enter the row and columns of matrix 2");
        int n2 = sc.nextInt();
        int m2 = sc.nextInt();
        int[][] arr2 = new int[n2][m2];
        input(arr2);
        System.out.println("Matrix 2: ");
        display(arr2);
      
        // performing matrix multiplication....
        if (m1 != n2) {
            System.out.println("Invlaid input");
            return;
        }
        int[][] res = matrix_mul(arr, arr2);
      
        System.out.println("Resulting matrix will be : ");
        display(res);
        sc.close();
    }
}
