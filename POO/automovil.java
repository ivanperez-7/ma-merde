public class automovil{
    private String color;
    private int llantas;
    private int cilindros;
    
    public void establecercolor(String ncolor){
        color = ncolor;
    }
    
    public String obtenercolor(){
        return color;
    }
    
    public void acelerar(int velocidad){
        System.out.println("Acelerando auto a " + velocidad + " km/h \n");
    }
}
