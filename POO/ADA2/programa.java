import java.util.ArrayList;
import java.util.Scanner;

public class programa{
    public static void main(String[] args){
        char flag;
        Scanner leerStr = new Scanner(System.in), leerInt = new Scanner(System.in), leerChar = new Scanner(System.in);
        ArrayList<Empleado> empleadolist = new ArrayList<Empleado>();
	
        System.out.println("\t\t\t\t\tSistema de recursos humanos");
        do{
            System.out.printf("Clave del Empleado: ");
            String clave = leerStr.nextLine();

            System.out.printf("Nombre del Empleado: ");
            String nombre = leerStr.nextLine();
            System.out.printf("Apellido paterno: ");
            String apellidoPaterno = leerStr.nextLine();
            System.out.printf("Apellido materno: ");
            String apellidoMaterno = leerStr.nextLine();

            System.out.println("\nFecha de nacimiento");
            System.out.printf("\tDía (dos dígitos): ");
            int dia = leerInt.nextInt();
            System.out.printf("\tMes (dos dígitos): ");
            int mes = leerInt.nextInt();
            System.out.printf("\tAño (cuatro dígitos): "); 
            int anio = leerInt.nextInt();
            Fecha nacimiento = new Fecha(dia,mes,anio);

            System.out.println("\nFecha de ingreso");
            System.out.printf("\tDía (dos dígitos): ");
            dia = leerInt.nextInt();
            System.out.printf("\tMes (dos dígitos): ");
            mes = leerInt.nextInt();
            System.out.printf("\tAño (cuatro dígitos): ");
            anio = leerInt.nextInt();
            Fecha ingreso = new Fecha(dia,mes,anio);

            System.out.println("\nDepartamento");
            System.out.printf("\tClave departamento: ");
            String clavedepto = leerStr.nextLine();
            System.out.printf("\tNombre departamento: ");
            String nombredepto = leerStr.nextLine();
            Depto depto = new Depto(clavedepto,nombredepto);

            ArrayList<Horario> horariolist = new ArrayList<Horario>();
            System.out.println("\nHorario");
            do {
                System.out.printf("\tDias: ");
                String dias = leerStr.nextLine();
                System.out.printf("\tInicio (ingrese hora y minuto): ");
                int horainicio = leerInt.nextInt(); int minutoinicio = leerInt.nextInt();
                System.out.printf("\tTermina (ingrese hora y minuto: ");
                int horatermina = leerInt.nextInt(); int minutotermina = leerInt.nextInt();

                Horario horario = new Horario(dias,horainicio,minutoinicio,horatermina,minutotermina);
                horariolist.add(horario);
                System.out.printf("\nDesea agregar otro horario? (S/N): ");
                do { flag = leerChar.next().charAt(0); } while(flag != 'N' && flag != 'n' && flag != 'S' && flag != 's');
            } while(flag != 'N' && flag != 'n');

            Empleado empleado = new Empleado(clave,nombre,apellidoMaterno,apellidoPaterno,nacimiento,ingreso,depto,horariolist);
            empleadolist.add(empleado);
            System.out.printf("\nDesea capturar otro empleado? (S/N): ");
            do { flag = leerChar.next().charAt(0); } while(flag != 'N' && flag != 'n' && flag != 'S' && flag != 's');
        } while(flag != 'N' && flag != 'n');

        System.out.println("\n\t\t\t\t\tListado de empleados registrados");
        System.out.printf("%-14s %-14s %-14s %-14s %-19s   %-19s %-14s\n","Clave","Nombre","A. Materno","A. Paterno","Fecha de nacimiento","Fecha de ingreso","Departamento");
	System.out.println("====================================================================================================================");

        for(int i = 0; i < empleadolist.size(); i++){
            Empleado emp = empleadolist.get(i);
            System.out.printf("%-14s %-14s %-14s %-14s %-19s   %-19s %-14s\n",emp.getClave(),emp.getNombre(),emp.getApellidoPaterno(),emp.getApellidoMaterno(),emp.nacimiento,emp.ingreso,emp.depto.getNombre());

            int j = 0; Horario hora;
            for(; j < emp.getSizeHorario()-1; j++){
                hora = emp.getHorario(j);
                System.out.printf("%s, ",hora);
            }
            hora = emp.getHorario(j);
            System.out.printf("%s\n",hora);
	    System.out.println("====================================================================================================================");
        }
    }
}
