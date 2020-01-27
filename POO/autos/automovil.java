public class automovil{
    private String color;
    private int llantas;
    private int cilindros;
    
    public automovil(String color, int llantas, int cilindros){
        establecercolor(color);
        establecerllantas(llantas);
        establecercilindros(cilindros);
    }

    public void establecercolor(String color){
        this.color = color;
    }
    
    public void establecerllantas(int llantas){
        if(llantas <= 0)
            this.llantas = 2;
        else
            this.llantas = llantas;
    }

    public void establecercilindros(int cilindros){
        if(cilindros <= 0)
            this.cilindros = 4;
        else
            this.cilindros = cilindros;
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

    public String toString(){
        return "Color: " + obtenercolor() + "\t Llantas: " + obtenerllantas() + "\t Cilindros: " + obtenercilindros() + "\n";
    }
}
