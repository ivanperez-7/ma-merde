public class automovil{
    private String color;
    private int llantas;
    private int cilindros;
    
    public void establecercolor(String ncolor){
        color = ncolor;
    }
    
    public void establecerllantas(int nllantas){
        llantas = nllantas;
    }

    public void establecercilindros(int ncilindros){
        cilindros = ncilindros;
    }

    public String obtenercolor(){
        return color;
    }

    public int obtenerllantas(){
        return llantas;
    }

    public int obtenercilindros(){
        return cilindros;
    }
    
    public void acelerar(int velocidad){
        System.out.println("Acelerando auto a " + velocidad + " km/h \n");
    }
}
