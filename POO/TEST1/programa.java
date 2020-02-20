import java.util.ArrayList;
import java.util.Scanner;
import Modelo.*;

public class programa{
    public static void main(String[] args){
        char flag, c;
        Scanner leerStr = new Scanner(System.in), leerInt = new Scanner(System.in), leerDouble = new Scanner(System.in), leerChar = new Scanner(System.in);
        ArrayList<Cliente> listaClientes = new ArrayList<Cliente>();

        System.out.println("\t\t\t\t\tSistema video club");
        do {
            System.out.printf("Clave de cliente: ");
            String clave = leerStr.nextLine();
            System.out.printf("Nombre de cliente: ");
            String nombre = leerStr.nextLine();

            System.out.println("\nFecha de ingreso");
            System.out.printf("\tDia: ");
            int dia = leerInt.nextInt();
            System.out.printf("\tMes: ");
            int mes = leerInt.nextInt();
            System.out.printf("\tAño: ");
            int anio = leerInt.nextInt();
            Fecha fechaIngreso = new Fecha(dia,mes,anio);

            System.out.printf("\nTipo de cliente:\n1. Cliente Consentido\n2. Cliente VIP\nOpcion: ");
            do {c = leerChar.next().charAt(0);} while(c != '1' && c != '2');

            if(c == '1'){       // Cliente Consentido
                System.out.printf("\nPeliculas rentadas por dia: ");
                int rentasPorDia = leerInt.nextInt();
                System.out.printf("Precio de renta por pelicula: ");
                double precioPorRenta = leerDouble.nextDouble();

                listaClientes.add(new ClienteConsentido(clave,nombre,fechaIngreso,rentasPorDia,precioPorRenta));
            }
            else{               // Cliente VIP
                System.out.printf("\nCosto diario de membresia: ");
                double costoDiario = leerDouble.nextDouble();

                listaClientes.add(new ClienteVIP(clave,nombre,fechaIngreso,costoDiario));     
            }

            System.out.printf("\nDesea capturar otro cliente? (S/N): ");
            do {flag = leerChar.next().charAt(0);} while(flag != 's' && flag != 'S' && flag != 'n' && flag != 'N');
        } while(flag != 'n' && flag != 'N');

        System.out.printf("\n%-7s %-25s %-22s %-20s %s\n","Clave","Nombre","Tipo de Cliente","Fecha de ingreso","Pago por dia");
        System.out.println("==========================================================================================");

        for(int i = 0; i < listaClientes.size(); i++){
            Cliente cliente = listaClientes.get(i);
            System.out.printf("%-7s %-25s %-22s %-20s %s\n",cliente.getClave(),cliente.getNombre(),cliente.getTipoCliente(),cliente.fechaIngreso,cliente.getPagoPorDia());
        }
    }
}
