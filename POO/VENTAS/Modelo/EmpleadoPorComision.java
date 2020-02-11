package Modelo;

public class EmpleadoPorComision{
    private String numSeguroSocial;
    private String nombre;
    private String apellidoPaterno;
    private String apellidoMaterno;
    private double tarifaComision;
    private double ventasBrutas;

    public EmpleadoPorComision(String numSeguroSocial, String nombre, String apellidoPaterno, String apellidoMaterno, double tarifaComision, double ventasBrutas){
        this.numSeguroSocial = numSeguroSocial;
        this.nombre = nombre;
        this.apellidoPaterno = apellidoPaterno;
        this.apellidoMaterno = apellidoMaterno;
        this.tarifaComision = tarifaComision;
        this.ventasBrutas = ventasBrutas;
    }

    public String getNumSeguroSocial(){
        return numSeguroSocial;
    }

    public String getNombre(){
        return nombre;
    }

    public String getApellidoPaterno(){
        return apellidoPaterno;
    }

    public String getApellidoMaterno(){
        return apellidoMaterno;
    }

    public double getTarifaComision(){
        return tarifaComision;
    }

    public double getVentasBrutas(){
        return ventasBrutas;
    }

    public double ingreso(){
        return getTarifaComision() * getVentasBrutas();
    }
}
