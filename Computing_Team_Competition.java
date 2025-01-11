import java.io.*;
import java.util.*;
public class Computing_Team_Competition {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();
		int[] hPuffs = new int[n/2];

		for (int i = 0; i < n/2; i++){
			hPuffs[i] = sc.nextInt();
		}
		int [] rClaws = new int[n/2];

		for (int i = 0; i < n/2; i++){
			rClaws[i] = sc.nextInt();
		}
		int[] theBestCombo = getBestCombo(n, hPuffs, rClaws);
		System.out.println(theBestCombo[0]);
		System.out.println(theBestCombo[1]);
        sc.close();
	}
	public static int[] getBestCombo(int n, int[] hPuffs, int[] rClaws){
	int max = 0;
	for (int i = 0; i < n/2; i++){
		for (int j = 0; j < n/2; j++){
			int temp = hPuffs[i] + rClaws[j];
			if (temp > max){
				max = temp;
			}
		}
	}
	int[] bestCombo = new int[max + 1]; 
	for (int i = 0; i < n/2; i++){
		for (int j = 0; j < n/2; j++){
			int combo = hPuffs[i] + rClaws[j];
			bestCombo[combo]++;
			}
		}
		int frequency = 0;
		int ans = 0;
		for (int i = 0; i < max; i++)
		if (bestCombo[i] > frequency){
			frequency = bestCombo[i];
			ans = i;
		}
		int theAnswer[] = new int[2];
		theAnswer[0] = ans;
		theAnswer[1] = frequency;
		return theAnswer;
 	}
}
/*How does this work:
creates an array with the max index being the max sum

for the example in the doc, it creates
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

next, it takes all of the sums and adds 1 too each index that matches the sums

so given the sums:
2, 3, 4, 5, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 13, 16:
[0, 0, 1, 1, 1, 3, 1, 1, 2, 1, 1, 1, 1, 1, 0, 0, 1]

after this we can tell that the index with the
max value in the area is the rating, and the element in that index is the frequency

Compile time is quite high, with a for loop in a for loop and iterating through a lot of 
elements in an array.
*/