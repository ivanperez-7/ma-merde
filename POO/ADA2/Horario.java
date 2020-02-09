import java.util.Formatter;

public class Horario{
    private String dias;
    private int horaInicio;
    private int minutoInicio;
    private int horaTermina;
    private int minutoTermina;
    private Formatter f = new Formatter(), g = new Formatter();

    public Horario(String dias, int horaInicio, int minutoInicio, int horaTermina, int minutoTermina){
        this.dias = dias;
        setHoraInicio(horaInicio);
        setMinutoInicio(minutoInicio);
        setHoraTermina(horaTermina);
        setMinutoTermina(minutoTermina);
    }

    public void setHoraInicio(int horaInicio){
        if(horaInicio < 0)
            this.horaInicio = 0;
        else if(horaInicio > 23)
            this.horaInicio = 23;
        else
            this.horaInicio = horaInicio;
    }

    public void setMinutoInicio(int minutoInicio){
        if(minutoInicio < 0)
            this.minutoInicio = 0;
        else if(minutoInicio >= 60)
            this.minutoInicio = 59;
        else
            this.minutoInicio = minutoInicio;
    }

    public void setHoraTermina(int horaTermina){
        if(horaTermina < 0)
            this.horaTermina = 0;
        else if(horaTermina > 23)
            this.horaTermina = 23;
        else
            this.horaTermina = horaTermina;
    }

    public void setMinutoTermina(int minutoTermina){
        if(minutoTermina < 0)
            this.minutoTermina = 0;
        else if(minutoTermina >= 60)
            this.minutoTermina = 59;
        else
            this.minutoTermina = minutoTermina;
    }

    public String getDias(){
        return dias;
    }

    public int getHoraInicio(){
        return horaInicio;
    }

    public int getMinutoInicio(){
        return minutoInicio;
    }

    public int getHoraTermina(){
        return horaTermina;
    }

    public int getMinutoTermina(){
        return minutoTermina;
    }

    public String toString(){
        return getDias() + " " + getHoraInicio() + ":" + f.format("%02d",getMinutoInicio()) + " - " + getHoraTermina() + ":" + g.format("%02d",getMinutoTermina());
    }
}
