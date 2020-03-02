import Modelo.*;
import java.util.Scanner;
import java.util.ArrayList;

public class programa{
    public static void main(String[] args){
        char opcion, flag = 0;
        String nombre, NSS;
        Scanner leerChar = new Scanner(System.in), leerInt = new Scanner(System.in), leerDouble = new Scanner(System.in), leerStr = new Scanner(System.in);
        ArrayList<Empleado> listaEmpleado = new ArrayList<Empleado>();

        do {
            System.out.printf("Ingrese una opción\n1. Empleado asalariado\n2. Empleado por horas\n3. Empleado por comisión\n4. Empleado asalariado por comisión\nOpcion: ");
            do {opcion = leerChar.next().charAt(0);} while (opcion != '1' && opcion != '2' && opcion != '3' && opcion != '4');

            switch(opcion){
                case '1':
                    System.out.println("\nEmpleado asalariado");

                    System.out.printf("\tNombre completo: ");
                    nombre = leerStr.nextLine();
                    System.out.printf("\tNumero de seguro social: ");
                    NSS = leerStr.nextLine();
                    System.out.printf("\tSueldo semanal: ");
                    double sueldoSemanal = leerDouble.nextDouble();

                    listaEmpleado.add(new EmpleadoAsalariado(nombre,NSS,sueldoSemanal));
                    break;

                case '2':
                    System.out.println("\nEmpleado por horas");

                    System.out.printf("\tNombre completo: ");
                    nombre = leerStr.nextLine();
                    System.out.printf("\tNumero de seguro social: ");
                    NSS = leerStr.nextLine();
                    System.out.printf("\tSueldo base: ");
                    double sueldoBase = leerDouble.nextDouble();
                    System.out.printf("\tHoras trabajadas: ");
                    int horas = leerInt.nextInt();

                    listaEmpleado.add(new EmpleadoPorHoras(nombre,NSS,sueldoBase,horas));
                    break;

                case '3':
                    System.out.println("\nEmpleado por comisión");

                    System.out.printf("\tNombre completo: ");
                    nombre = leerStr.nextLine();
                    System.out.printf("\tNumero de seguro social: ");
                    NSS = leerStr.nextLine();
                    System.out.printf("\tTarifa de comisión: ");
                    double tarifaComision = leerDouble.nextDouble();
                    System.out.printf("\tVentas brutas: ");
                    double ventasBrutas = leerDouble.nextDouble();

                    listaEmpleado.add(new EmpleadoPorHoras(nombre,NSS,tarifaComision,ventasBrutas));
                    break;

                case '4':
                    System.out.println("\nEmpleado asalariado por comisión");
                    
                    System.out.printf("\tNombre completo: ");
                    nombre = leerStr.nextLine();
                    System.out.printf("\tNumero de seguro social: ");
                    NSS = leerStr.nextLine();
                    System.out.printf("\tTarifa de comisión: ");
                    double tarifaComision = leerDouble.nextDouble();
                    System.out.printf("\tVentas brutas: ");
                    double ventasBrutas = leerDouble.nextDouble();
                    System.out.printf("\tSalario base: ");
                    double salarioBase = leerDouble.nextDouble();

                    listaEmpleado.add(new EmpleadoPorHoras(nombre,NSS,tarifaComision,ventasBrutas,salarioBase));
                    break;

                default:
                    ;
            }
        } while(flag != 'n' && flag != 'N');
    }
}
