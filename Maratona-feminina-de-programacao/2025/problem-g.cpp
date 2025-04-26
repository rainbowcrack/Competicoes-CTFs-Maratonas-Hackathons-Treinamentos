import java.util.Scanner;

public class Mixer {
    public static void main(String[] args) {
        
        Scanner teclado = new Scanner(System.in);
        String nome = teclado.nextLine();
        
        // string acumuladoras
        String nomePar = "", nomeImpar = "";
        
        // separa os as string pares e impares no output
        for (int i = 0; i < nome.length(); i++) {
            if (i % 2 == 0) {
                nomePar += nome.charAt(i); 
            } else {
                nomeImpar += nome.charAt(i);  
            }
        }
        
        System.out.println(nomePar);
        System.out.println(nomeImpar);

	    teclado.close();
    }
}
