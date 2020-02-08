public class Fecha{
    private int dia;
    private int mes;
    private int anio;

    public Fecha(int dia, int mes, int anio){
        setAnio(anio);
        setMes(mes);
        setDia(dia);
    }

    public boolean isLeap(int year){
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }

    public void setDia(int dia){
        int lim;
        
        if(dia < 1){
            this.dia = 1;
            return ;
        }
        if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
            lim = 31;
        else if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
            lim = 30;
        else if(isLeap(getAnio()))
            lim = 29;
        else
            lim = 28;

        if(dia > lim)
            this.dia = lim;
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
