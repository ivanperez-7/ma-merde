package Modelo;

public class Aguila extends Animal{
    private double velocidadVuelo;

    public Aguila(String nombre, int edad, double velocidadVuelo){
        super(nombre,edad);
        this.velocidadVuelo = velocidadVuelo;
    }

    public void setVelocidadVuelo(double velocidadVuelo){
        this.velocidadVuelo = velocidadVuelo;
    }

    public double getVelocidadVuelo(){
        return velocidadVuelo;
    }

    public String mover(){
        return "Volando...";
    }

    public String toString(){
        return super.toString() + ", velocidad de vuelo: " + getVelocidadVuelo();
    }
}
