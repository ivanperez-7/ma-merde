package Modelo;

public abstract class Empleado implements PorPagar{
    private String nombre;
    private String NSS;

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

    public String getNombre(){
        return nombre;
    }

    public String getNSS(){
        return NSS;
    }

    public String toString(){
        return "Nombre: " + getNombre() + "\nNumero de seguro social: " + getNSS();
    }
}
