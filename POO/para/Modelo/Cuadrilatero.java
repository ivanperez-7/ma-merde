package Modelo;

public class Cuadrilatero{
    public Coordenada p1;
    public Coordenada p2;
    public Coordenada p3;
    public Coordenada p4;
    private double altura;

    public Cuadrilatero(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y, double p4x, double p4y){
        p1 = new Coordenada(p1x,p1y);
        p2 = new Coordenada(p2x,p2y);
        p3 = new Coordenada(p3x,p3y);
        p4 = new Coordenada(p4x,p4y);
    }

    public void setAltura(double altura){
        this.altura = altura;
    }

    public double getAltura(){
        return altura;
    }

    public double lado1(){
        return Math.sqrt(Math.pow(p1.getX() - p2.getX(),2) + Math.pow(p1.getY() - p2.getY(),2));
    }

    public double lado2(){
        return Math.sqrt(Math.pow(p2.getX() - p3.getX(),2) + Math.pow(p2.getY() - p3.getY(),2));
    }

    public double lado3(){
        return Math.sqrt(Math.pow(p3.getX() - p4.getX(),2) + Math.pow(p3.getY() - p4.getY(),2));
    }

    public double lado4(){
        return Math.sqrt(Math.pow(p4.getX() - p1.getX(),2) + Math.pow(p4.getY() - p1.getY(),2));
    }
}
