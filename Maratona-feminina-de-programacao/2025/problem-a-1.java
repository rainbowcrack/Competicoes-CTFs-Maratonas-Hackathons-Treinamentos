import java.util.Arrays;
import java.util.Scanner;

public class Oscar {
    public static void main(String[] args) {
        
        Scanner teclado = new Scanner(System.in);
        
        int TAM, K;
        TAM = teclado.nextInt();
        K = teclado.nextInt();   
        
        int[] amplitudes = new int[TAM];
        
        // ler amplitudes ordenadas
        for (int i = 0; i < TAM; i++) {
            amplitudes[i] = teclado.nextInt();
        }
        
        Arrays.sort(amplitudes);
        
        // k ate M, valores >= ks
        for (int i = 1; i <= K; i++) {
            int count = 0;
        
            for (int j = 0; j < TAM; j++) {
                if (amplitudes[j] >= i) {
                    count++;
                }
            }
            
            System.out.print(count + " ");
        }
        
        System.out.println(); // endl
        teclado.close();
    }
}
