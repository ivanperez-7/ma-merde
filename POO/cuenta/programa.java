import java.util.Scanner;

public class programa{
    public static void main(String[] args){
        Scanner leerStr = new Scanner(System.in), leerFloat = new Scanner(System.in);

        System.out.println("Ingrese numero de cuenta:");
        String numero = leerStr.nextLine();
        System.out.println("Ingrese una descripcion de la cuenta:");
        String descripcion = leerStr.nextLine();

        Cuenta mio = new Cuenta(numero,descripcion);
        float saldo = 0;
        do {
            mio.abonar(saldo);
            System.out.println("\nSaldo actual : " + mio.obtenerSaldo());
            System.out.println("Ingrese un nuevo saldo : ");
            saldo = leerFloat.nextFloat();
        } while(saldo != 0);

        System.out.println("\nSaldo final : " + mio.obtenerSaldo());
    }
}
