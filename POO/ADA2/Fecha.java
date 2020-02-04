public class Fecha{
    private int dia;
    private int mes;
    private int anio;

    public Fecha(int dia, int mes, int anio){
        setDia(dia);
        setMes(mes);
        setAnio(anio);
    }

    public void setDia(int dia){
        if(dia < 1)
            this.dia = 1;
        else if(dia > 31)
            this.dia = 31;
        else
            this.dia = dia;
    }

    public void setMes(int mes){
        if(mes < 1)
            this.mes = 1;
        else if(mes > 12)
            this.mes = 12;
        else
            this.mes = mes;
    }

    public void setAnio(int anio){
        if(anio < 1)
            this.anio = 1;
        else
            this.anio = anio;
    }

    public int getDia(){
        return dia;
    }

    public int getMes(){
        return mes;
    }

    public int getAnio(){
        return anio;
    }

    public String toString(){
        return getDia() + "/" + getMes() + "/" + getAnio();
    }
}
