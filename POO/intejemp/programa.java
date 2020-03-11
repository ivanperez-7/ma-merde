import Modelo.*;
import java.util.ArrayList;

public class programa {
    public static void main(String[] args) {
        ArrayList<PorPagar> listaPagos = new ArrayList<PorPagar>();

        listaPagos.add(new Factura("01","Motosierra",5,560.00));
        listaPagos.add(new Factura("02","Casa",10,1000000.00));
        listaPagos.add(new Factura("03","Computadora",1000,50000.00));
        listaPagos.add(new EmpleadoAsalariado("Ivan Perez","7582334",7500.00));
        listaPagos.add(new EmpleadoAsalariado("Yulya Lailun Alil","584934",15000.00));

        for(int i = 0; i < listaPagos.size(); i++)
            System.out.println(listaPagos.get(i) + "\nCuenta por pagar = " + listaPagos.get(i).obtenerMontoPago() + "\n");
    }
}
