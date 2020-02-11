package Modelo;

public class Cuadrilatero{
    private Coordenada p1;
    private Coordenada p2;
    private Coordenada p3;
    private Coordenada p4;

    public Cuadrilatero(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y, double p4x, double p4y){
        p1 = new Coordenada(p1x,p1y);
        p2 = new Coordenada(p2x,p2y);
        p3 = new Coordenada(p3x,p3y);
        p4 = new Coordenada(p4x,p4y);
    }

    public Coordenada getP1(){
        return p1;
    }

    public Coordenada getP2(){
        return p2;
    }

    public Coordenada getP3(){
        return p3;
    }

    public Coordenada getP4(){
        return p4;
    }

    public double lado1(){
        return Math.sqrt(Math.pow(getP1().getX() - getP2().getX(),2) + Math.pow(getP1().getY() - getP2().getY(),2));
    }

    public double lado2(){
        return Math.sqrt(Math.pow(getP2().getX() - getP3().getX(),2) + Math.pow(getP2().getY() - getP3().getY(),2));
    }

    public double lado3(){
        return Math.sqrt(Math.pow(getP3().getX() - getP4().getX(),2) + Math.pow(getP3().getY() - getP4().getY(),2));
    }

    public double lado4(){
        return Math.sqrt(Math.pow(getP4().getX() - getP1().getX(),2) + Math.pow(getP4().getY() - getP1().getY(),2));
    }
}
