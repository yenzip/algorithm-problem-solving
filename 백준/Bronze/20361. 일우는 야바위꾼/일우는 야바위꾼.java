import java.util.Scanner;

public class Main {
	static int ans;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int X = sc.nextInt();
		int K = sc.nextInt();
		
		ans = X;
		
		for(int i = 0; i < K; i++) {
			int A = sc.nextInt();
			int B = sc.nextInt();
			if(ans == A) {
				ans = B;
			} else if(ans == B) {
				ans = A;
			}
		}
		
		System.out.println(ans);
		
		sc.close();
	}

}
