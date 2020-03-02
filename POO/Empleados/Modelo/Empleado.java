package Modelo;

public abstract class Empleado{
    private String nombre;
    private String NSS;
    private double ingresos;

    public Empleado(String nombre, String NSS){
        this.nombre = nombre;
        this.NSS = NSS;
    }

    public void setNombre(String nombre){
        this.nombre = nombre;
    }

    public void setNSS(String NSS){
        this.NSS = NSS;
    }

    public void setIngresos(double ingresos){
        this.ingresos = ingresos;
    }

    public String getNombre(){
        return nombre;
    }

    public String getNSS(){
        return NSS;
    }

    public double getIngresos(){
        return ingresos;
    }

    public abstract void obtenerIngresos();
}
