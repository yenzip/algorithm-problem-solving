import java.io.*;
import java.util.*;

public class Solution {
	private static Queue<Integer> q;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		for(int tc = 1; tc <= 10; tc++) {
			br.readLine();
			st = new StringTokenizer(br.readLine());
			q = new LinkedList<>();
			
			for(int i = 0; i < 8; i++) {
				q.offer(Integer.parseInt(st.nextToken()));
			}
			
			boolean isRun = true;
			while(isRun) {
				for(int i = 1; i <= 5; i++) {
					int x = q.poll() - i;
					if(x <= 0) {
						isRun = false;
						break;
					}
					q.offer(x);
				}
				if(!isRun) {
					q.offer(0);
				}
			}
			
			System.out.print("#" + tc);
			while(!q.isEmpty()) {
				System.out.print(" " + q.poll());
			}
			System.out.println();
		}
	}

}