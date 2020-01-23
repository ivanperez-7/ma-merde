public class DiaAnio{
    private int anio;
    private int mes;
    private int dia;

    public DiaAnio(int anio, int mes, int dia){
        this.anio = anio;
        this.mes = mes;
        this.dia = dia;
    }

    public void setAnio(int anio){
        this.anio = anio;
    }

    public void setMes(int mes){
        this.mes = mes;
    }

    public void setDia(int dia){
        this.dia = dia;
    }
 
    public int getAnio(){
        return anio;
    }

    public int getMes(){
        return mes;
    }

    public int getDia(){
        return dia;
    }

    public boolean igualar(int anio, int mes, int dia){
        return (getAnio() == anio && getMes() == mes && getDia() == dia);
    }

    public void visualizar(int anio, int mes, int dia){
        if(igualar(anio,mes,dia))
            System.out.println("FELIZ CUMPLEAÑOS :3");
        else
            System.out.println("FELIZ NO CUMPLEAÑOS XDXD");
    }

    public String toString(){
        return getDia() + "/" + getMes() + "/" + getAnio();
    }
}
