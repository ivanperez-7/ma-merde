import java.util.Scanner;
import java.util.ArrayList;

public class programa{
    public static void main(String[] args){
        Scanner leerInt = new Scanner(System.in), leerStr = new Scanner(System.in), leerDouble = new Scanner(System.in);
        ArrayList<Factura> lista = new ArrayList();

        System.out.println("==========\nProducto\n==========\nNumero de factura: ");
        int nFactura = leerInt.nextInt();

        while(nFactura >= 1){
            System.out.println("Numero de pieza: ");
            int nPieza = leerInt.nextInt();
            System.out.println("Descripcion de la pieza: ");
            String descripcion = leerStr.nextLine();
            System.out.println("Cantidad de piezas: ");
            int cantidad = leerInt.nextInt();
            System.out.println("Precio por pieza: ");
            double precio = leerDouble.nextDouble();

            System.out.println("Dia de venta: ");
            int dia = leerInt.nextInt();
            System.out.println("Mes de venta: ");
            int mes = leerInt.nextInt();
            System.out.println("Año de venta: ");
            int anio = leerInt.nextInt();
            Fecha fechaventa = new Fecha(dia,mes,anio);

            System.out.println("\n==========\nVendedor\n==========\nClave de empleado: ");
            String nEmpleado = leerStr.nextLine();
            System.out.println("Nombre: ");
            String nombre = leerStr.nextLine();
            System.out.println("Apellido paterno: ");
            String AP = leerStr.nextLine();
            System.out.println("Apellido materno: ");
            String AM = leerStr.nextLine();
            System.out.println("Dia de nacimiento: ");
            int dian = leerInt.nextInt();
            System.out.println("mes de nacimiento: ");
            int mesn = leerInt.nextInt();
            System.out.println("Año de nacimiento: ");
            int anion = leerInt.nextInt();
            Fecha nacimiento = new Fecha(dian,mesn,anion);
            Empleado vendedor = new Empleado(nEmpleado,nombre,AP,AM,nacimiento);

            Factura ejemplo = new Factura(nFactura,nPieza,descripcion,cantidad,precio,fechaventa,vendedor);
            lista.add(ejemplo);

            System.out.println("\n\n==========\nProducto\n==========\nNumero de factura: ");
            nFactura = leerInt.nextInt();
        }

        for(int i = 0; i<lista.size();i++)
            System.out.println("\n-------------------------------------\n"+lista.get(i));
    }
}
