package Modelo;

public class EmpleadoPorComision extends Empleado{
    private double tarifaComision;
    private double ventasBrutas;

    public EmpleadoPorComision(String nombre, String NSS, double tarifaComision, double ventasBrutas){
        super(nombre,NSS);
        setTarifaComision(tarifaComision);
        setVentasBrutas(ventasBrutas);
    }

    public void setTarifaComision(double tarifaComision){
        if(tarifaComision <= 0)
            this.tarifaComision = 0;
        else
            this.tarifaComision = tarifaComision;
    }

    public void setVentasBrutas(double ventasBrutas){
        if(ventasBrutas <= 0)
            this.ventasBrutas = 0;
        else
            this.ventasBrutas = ventasBrutas;
    }

    public double getTarifaComision(){
        return tarifaComision;
    }

    public double ventasBrutas(){
        return ventasBrutas;
    }

    public void obtenerIngresos(){
        setIngresos(ventasBrutas * tarifaComision);
    }
}
