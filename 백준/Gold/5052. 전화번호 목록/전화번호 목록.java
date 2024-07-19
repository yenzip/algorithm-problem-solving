import java.io.*;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int t = Integer.parseInt(br.readLine());
		
		while(t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			String[] tel = new String[n];
			
			for(int i = 0; i < n; i++) {
				tel[i] = br.readLine();
			}
			
			Arrays.sort(tel);
			
			boolean isConsistent = false;
			for(int i = 0; i < n - 1; i++) {
				if(tel[i + 1].indexOf(tel[i]) == 0) {
					isConsistent = true;
					break;
				}
			}
			
			if(isConsistent) {
				sb.append("NO\n");
			} else {
				sb.append("YES\n");
			}
		}
		
		System.out.println(sb);
		
		br.close();
	}
    
}