import Modelo.*;

public class programa{
    public static void main(String[] args){
        Trapecio trapecio = new Trapecio(2,5,0,0,9,0,7,5);
        Romboide romboide = new Romboide(2,5,0,0,5,0,7,5);
        Rectangulo rectangulo = new Rectangulo(0,5,0,0,10,0,10,5);
        Cuadrado cuadrado = new Cuadrado(0,3,0,0,3,0,3,3);

        System.out.println("Area trapecio = "+trapecio.area() + "\nArea romboide = " +romboide.area() + "\nArea rectangulo = "+rectangulo.area() + "\nArea cuadrado = "+cuadrado.area());
    }
}
