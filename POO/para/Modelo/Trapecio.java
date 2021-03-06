package Modelo;

public class Trapecio extends Cuadrilatero{
    public Trapecio(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y, double p4x, double p4y){
        super(p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y);
        setAltura(Math.abs(p3.getY() - p1.getY()));
    }

    public double area(){
        return (getAltura()*(lado2()+lado4()))/2;       
    }
}
