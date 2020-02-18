package Modelo;

public class Conejo extends Animal{
    private double alturaBrinco;

    public Conejo(String nombre, int edad, double alturaBrinco){
        super(nombre,edad);
        this.alturaBrinco = alturaBrinco;
    }

    public void setAlturaBrinco(double alturaBrinco){
        this.alturaBrinco = alturaBrinco;
    }

    public double getAlturaBrinco(){
        return alturaBrinco;
    }

    public String mover(){
        return "Brincando...";
    }

    public String toString(){
        return super.toString() + ", altura de brinco: " + getAlturaBrinco();
    }
}
