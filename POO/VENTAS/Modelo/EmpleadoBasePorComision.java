package Modelo;

public class EmpleadoBasePorComision extends EmpleadoPorComision{
    private double sueldoBase;

    public EmpleadoBasePorComision(String numSeguroSocial, String nombre, String apellidoPaterno, String apellidoMaterno, double tarifaComision, double ventasBrutas, double sueldoBase){
        super(numSeguroSocial, nombre, apellidoPaterno, apellidoMaterno, tarifaComision, ventasBrutas);
        this.sueldoBase = sueldoBase;
    }


}
