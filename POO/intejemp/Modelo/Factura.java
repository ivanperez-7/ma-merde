package Modelo;

public class Factura implements PorPagar {
    private String numPieza;
    private String descripcionPieza;
    private int cantidad;
    private double precioArticulo;

    public Factura(String numPieza, String descripcionPieza, int cantidad, double precioArticulo) {
        this.numPieza = numPieza;
        this.descripcionPieza = descripcionPieza;
        this.cantidad = cantidad;
        this.precioArticulo = precioArticulo;
    }

    public void setNumPieza(String numPieza) {
        this.numPieza = numPieza;
    }

    public void setDescripcionPieza(String descripcionPieza) {
        this.descripcionPieza = descripcionPieza;
    }

    public void setCantidad(int cantidad) {
        this.cantidad = cantidad;
    }

    public void setPrecioArticulo(double precioArticulo) {
        this.precioArticulo = precioArticulo;
    }

    public String getNumPieza() {
        return numPieza;
    }

    public String getDescripcionPieza() {
        return descripcionPieza;
    }

    public int getCantidad() {
        return cantidad;
    }

    public double getPrecioArticulo() {
        return precioArticulo;
    }

    public double obtenerMontoPago() {
        return getCantidad() * getPrecioArticulo();
    }

    public String toString() {
        return "Factura{" +
                "numPieza='" + numPieza + '\'' +
                ", descripcionPieza='" + descripcionPieza + '\'' +
                ", cantidad=" + cantidad +
                ", precioArticulo=" + precioArticulo +
                '}';
    }
}
