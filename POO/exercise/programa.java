import java.util.Scanner;

public class programa{
    public static void main(String[] args){
        Scanner leerStr = new Scanner(System.in), leerint = new Scanner(System.in);

        System.out.println("Ingrese nombre:");
        String nombre = leerStr.nextLine();
        System.out.println("Ingrese ISSN:");
        String ISSN = leerStr.nextLine();
        System.out.println("Ingrese año:");
        int anio = leerint.nextInt();
        System.out.println("Ingrese editorial:");
        String editorial = leerStr.nextLine();

        Revista ejemplo = new Revista(nombre,ISSN,anio,editorial);

        System.out.println("\nDatos del libro \n" + ejemplo.imprimir());
    }
}
