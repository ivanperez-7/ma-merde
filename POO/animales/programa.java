import java.util.ArrayList;
import Modelo.*;

public class programa{
    public static void main(String[] args){
        ArrayList<Animal> listaAnimales = new ArrayList<Animal>();

        listaAnimales.add(new Conejo("Nube",3,3.0));
        listaAnimales.add(new Aguila("Holis",6,80.0));
        listaAnimales.add(new Serpiente("Haag",10,3.0));

        for(int i = 0; i < listaAnimales.size(); i++){
            System.out.println(listaAnimales.get(i));
            System.out.println("Se mueve: " + listaAnimales.get(i).mover());
        }
    }
}
