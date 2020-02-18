package Modelo;

public abstract class Animal{
    private String nombre;
    private int edad;

    public Animal(String nombre, int edad){
        this.nombre = nombre;
        this.edad = edad;
    }

    public void setNombre(String nombre){
        this.nombre = nombre;
    }

    public void setEdad(int edad){
        this.edad = edad;
    }

    public String getNombre(){
        return nombre;
    }

    public int getEdad(){
        return edad;
    }

    public abstract String mover();

    public String toString(){
        return "Nombre: " + getNombre() + ", edad: " + getEdad();
    }
}
