import java.io.*;
import java.util.*;
public class Fishing_Frenzy {
	public static void main(String[] args) throws IOException {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int k = sc.nextInt();
		sc.nextLine();
		int[] fish = new int[n];
		for (int i = 0; i < n; i++) {
			fish[i] = sc.nextInt();
		}
		System.out.print(bestCatch(n, k, fish));
        sc.close();
	}
//n = number of meters
//k = length of net
//fish = number of fish at each meter
	public static int bestCatch(int n, int k, int[] fish) {
		int max_fish = 0;
		int ans = 0;
		for (int i = 0; i <= n - k; i++) {
			int curr_fish = 0;
			for (int j = 0; j < k; j++) {
				curr_fish += fish[i + j];
			}
			if (curr_fish > max_fish) {
				ans = i;
				max_fish = curr_fish;
			}
		}
		return ans + 1;
	}
}

