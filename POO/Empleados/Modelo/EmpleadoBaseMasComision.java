package Modelo;

public class EmpleadoBaseMasComision extends EmpleadoPorComision{
    private double salarioBase;

    public EmpleadoBaseMasComision(String nombre, String NSS, double tarifaComision, double ventasBrutas, double salarioBase){
        super(nombre,NSS,tarifaComision,ventasBrutas);
        setSalarioBase(salarioBase);
    }

    public void setSalarioBase(double salarioBase){
        if(salarioBase <= 0)
            this.salarioBase = 0;
        else
            this.salarioBase = salarioBase;
    }

    public double getSalarioBase(){
        return salarioBase;
    }

    public void obtenerIngresos(){
        setIngresos(tarifaComision*ventasBrutas + salarioBase);
    }
}
