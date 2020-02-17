import java.util.Scanner;
import Modelo.*;

public class programa{
    public static void main(String[] args){
        Scanner leerChar = new Scanner(System.in), leerDouble = new Scanner(System.in);
        char op;

        System.out.printf("1. Area Cuadrado\n2. Area rectangulo\n3. Area romboide\n4. Area trapecio\nIngresa una opcion: ");
        do {op = leerChar.next().charAt(0);} while(op != '1' && op != '2' && op != '3' && op != '4');
        System.out.printf("\nIngrese los puntos en el siguiente orden:\n\tp1 ----- p4\n\t   |   |\n\t   |   |\n\tp2 ----- p3\n\n");

        System.out.printf("Absisa de p1: ");
        double p1x = leerDouble.nextDouble();
        System.out.printf("Ordenada de p1: ");
        double p1y = leerDouble.nextDouble();

        System.out.printf("Absisa de p2: ");
        double p2x = leerDouble.nextDouble();
        System.out.printf("Ordenada de p2: ");
        double p2y = leerDouble.nextDouble();

        System.out.printf("Absisa de p3: ");
        double p3x = leerDouble.nextDouble();
        System.out.printf("Ordenada de p3: ");
        double p3y = leerDouble.nextDouble();

        System.out.printf("Absisa de p4: ");
        double p4x = leerDouble.nextDouble();
        System.out.printf("Ordenada de p4: ");
        double p4y = leerDouble.nextDouble();

        System.out.printf("\nArea de la figura: ");
        switch(op){
            case '1':
                Cuadrado cuadrado = new Cuadrado(p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y);
                System.out.println(cuadrado.area());
                break;

            case '2':
                Rectangulo rectangulo = new Rectangulo(p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y);
                System.out.println(rectangulo.area());
                break;

            case '3':
                Romboide romboide = new Romboide(p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y);
                System.out.println(romboide.area());
                break;

            case '4':
                Trapecio trapecio = new Trapecio(p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y);
                System.out.println(trapecio.area());
                break;

            default:
                ;
        }
    }
}
