import java.util.Scanner;

public class Crearauto{
    public static void main(){
        automovil trax = new automovil();
        int velocidad;
        String col;
        Scanner captura = new Scanner(System.in);
        
        System.out.println("Escriba la velocidad a acelerar: ");
        velocidad = captura.nextInt();
        col = trax.obtenercolor();
        
        System.out.println("Color: " + col);
        trax.acelerar(velocidad);
    }
}
