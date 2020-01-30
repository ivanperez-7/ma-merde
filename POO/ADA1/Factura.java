public class Factura{
    private int nFactura;
    private int nPieza;
    private String descripcion;
    private int cantidad;
    private double precio;
    public Empleado vendedor;
    public Fecha fecha;

    public Factura(int nFactura, int nPieza, String descripcion, int cantidad, double precio, Fecha fecha, Empleado vendedor){
        this.nFactura = nFactura;
        this.nPieza = nPieza;
        this.descripcion = descripcion;
        setCantidad(cantidad);
        setPrecio(precio);
        this.fecha = fecha;
        this.vendedor = vendedor;
    }

    public void setCantidad(int cantidad){
        if(cantidad <= 0)
            this.cantidad = 0;
        else
            this.cantidad = cantidad;
    }

    public void setPrecio(double precio){
        if(precio <= 0.0)
            this.precio = 0;
        else
            this.precio = precio;
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
        return getCantidad() * getPrecio();
    }

    public String toString(){
        return "Factura: " + getNumero() + "\n\nNúmero de pieza: " + getPieza() + "\nDescripción: " + getDescripcion() + "\nCantidad: " + getCantidad() + "\nPrecio por pieza: $" + getPrecio() + "\nVendedor: " + vendedor.toString() + "\nFecha de la fecha: " + fecha.toString() + "\n\n\tMonto total: $" + obtenerMontoFactura();
    }
}
