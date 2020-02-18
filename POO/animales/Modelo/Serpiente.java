package Modelo;

public class Serpiente extends Animal{
    private double longitud;

    public Serpiente(String nombre, int edad, double longitud){
        super(nombre,edad);
        this.longitud = longitud;
    }

    public void setLongitud(double longitud){
        this.longitud = longitud;
    }

    public double getLongitud(){
        return longitud;
    }

    public String mover(){
        return "Moviendo...";
    }

    public String toString(){
        return super.toString() + ", longitud: " + getLongitud();
    }
}
