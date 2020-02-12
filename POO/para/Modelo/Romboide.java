package Modelo;

public class Romboide extends Paralelogramo{
    public Romboide(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y, double p4x, double p4y){
        super(p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y);
        setAltura(Math.abs(getP3().getY() - getP1().getY()));
    }
}
