import java.util.Scanner;

public class Crearauto{
    public static void main(String[] args){
        automovil trax = new automovil("Verde",4,4);
        Scanner captura = new Scanner(System.in);
        
        System.out.println("Escriba la velocidad a acelerar: ");
        int velocidad;
        velocidad = captura.nextInt();
       
        trax.acelerar(velocidad);
        System.out.println(trax);
    }
}
