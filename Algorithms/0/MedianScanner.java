import java.util.Arrays;
import java.util.Scanner;


public class MedianScanner {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
    
        // Read first line -> Number of elements
        int k = scanner.nextInt();
        int[] array = new int[k];
        
        // Read elements into array
        for (int i = 0; i < k; i++) {
            array[i] = scanner.nextInt();
        }
        
        // Compute median
        Arrays.sort(array);
        if (k%2 == 1){
            System.out.println(array[k/2]);
        }
        else {
            System.out.println((array[k/2]+array[k/2 - 1])*0.5);
        }
	}
}
