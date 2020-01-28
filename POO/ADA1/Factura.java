public class Factura{
    private int nFactura;
    private int nPieza;
    private String descripcion;
    private int cantidad;
    private double precio;
    private Empleado vendedor;
    private Fecha venta;

    public Factura(int nFactura, int nPieza, String descripcion, int cantidad, double precio, Fecha venta, Empleado vendedor){
        this.nFactura = nFactura;
        this.nPieza = nPieza;
        this.descripcion = descripcion;
        this.cantidad = cantidad;
        this.precio = precio;
        this.venta = venta;
        this.vendedor = vendedor;
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
