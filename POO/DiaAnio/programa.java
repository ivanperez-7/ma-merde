import java.util.Scanner;

public class programa{
    public static void main(String[] args){
        int dia, mes, anio;
        Scanner leer = new Scanner(System.in);

        System.out.println("Ingrese dia de cumpleaños:");
        dia = leer.nextInt();
        System.out.println("Ingrese mes de cumpleaños:");
        mes = leer.nextInt();
        System.out.println("Ingrese año de cumpleaños:");
        anio = leer.nextInt();

        DiaAnio cumple = new DiaAnio(anio,mes,dia);
        System.out.println("\n"+cumple);

        System.out.println("Ingrese dia:");
        dia = leer.nextInt();
        System.out.println("Ingrese mes:");
        mes = leer.nextInt();
        System.out.println("Ingrese año:");
        anio = leer.nextInt();
        DiaAnio nueva = new DiaAnio(anio,mes,dia);

        cumple.visualizar(nueva.getAnio(),nueva.getMes(),nueva.getDia());
    }
}
