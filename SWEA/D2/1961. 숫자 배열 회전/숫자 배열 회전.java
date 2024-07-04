import java.io.*;
import java.util.*;
 
class Solution {
    static int N;
     
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
         
        int T = Integer.parseInt(st.nextToken());
         
        for(int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            int[][] A = new int[N][N];
             
             
            for(int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < N; j++) {
                    A[i][j] = Integer.parseInt(st.nextToken());
                }
            }
             
            int[][] A_90 = rotation90(A);
            int[][] A_180 = rotation90(A_90);
            int[][] A_270 = rotation90(A_180);
             
            System.out.println("#" + tc);
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    System.out.print(A_90[i][j]);
                }
                System.out.print(" ");
                 
                for(int j = 0; j < N; j++) {
                    System.out.print(A_180[i][j]);
                }
                System.out.print(" ");
                     
                for(int j = 0; j < N; j++) {
                    System.out.print(A_270[i][j]);
                }
                System.out.println();
            }
        }
         
        br.close();
    }
     
    private static int[][] rotation90(int[][] A) {
        int[][] result = new int[N][N];
         
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                result[i][j] = A[N - j - 1][i];
            }
        }
     
        return result;
    }
     
    // (0, 0) -> (2, 0)    (0, 1) -> (1, 2)    (0, 2) -> (2, 2)
    // (1, 0) -> (2, 1)    (1, 1) -> (1, 1)    (1, 2) -> (2, 1)
    // (2, 0) -> (2, 2)    (2, 1) -> (1, 0)    (2, 2) -> (2, 0)
}