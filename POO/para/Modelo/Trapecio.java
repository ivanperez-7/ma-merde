package Modelo;

public class Trapecio extends Cuadrilatero{
    private double altura;

    public Trapecio(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y, double p4x, double p4y, double altura){
        super(p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y);
        this.altura = altura;
    }
}
