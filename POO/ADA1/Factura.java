public class Factura{
    private int nFactura;
    private int nPieza;
    private String descripcion;
    private int cantidad;
    private double precio;
    Empleado vendedor;
    Fecha venta;

    public Factura(int nFactura, int nPieza, String descripcion, int cantidad, double precio, int dia, int mes, int anio, String nEmpleado, String nombre, String apellidoP, String apellidoM, int dian, int mesn, int anion){
        this.nFactura = nFactura;
        this.nPieza = nPieza;
        this.descripcion = descripcion;
        this.cantidad = cantidad;
        this.precio = precio;
        venta = new Fecha(dia,mes,anio);
        vendedor = new Empleado(nEmpleado, nombre, apellidoP, apellidoM, dian, mesn, anion);
    }

    public int getNumero(){
        return nFactura;
    }

    public int getPieza(){
        return nPieza;
    }

    public String getDescripcion(){
        return descripcion;
    }

    public int getCantidad(){
        return cantidad;
    }

    public double getPrecio(){
        return precio;
    }

    public double obtenerMontoFactura(){
        return cantidad*precio;
    }

    public String toString(){
        return "Factura: " + getNumero() + "\n\nNúmero de pieza: " + getPieza() + "\nDescripción: " + getDescripcion() + "\nCantidad: " + getCantidad() + "\nPrecio por pieza: $" + getPrecio() + "\nVendedor: " + vendedor.toString() + "\nFecha de la venta: " + venta.toString() + "\n\n\tMonto total: $" + obtenerMontoFactura();
    }
}
