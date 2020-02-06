public class Horario{
    private String dias;
    private int horainicio;
    private int minutoinicio;
    private int horatermina;
    private int minutotermina;

    public Horario(String dias, int horainicio, int minutoinicio, int horatermina, int minutotermina){
        this.dias = dias;
        this.horainicio = horainicio;
        this.minutoinicio = minutoinicio;
        this.horatermina = horatermina;
        this.minutotermina = minutotermina;
    }

    public void setHoraInicio(int horainicio){
        if(horainicio < 0)
            this.horainicio = 0;
        else if(horainicio > 24)
            this.horainicio = 24;
        else
            this.horainicio = horainicio;
    }

    public void setMinutoInicio(int minutoinicio){
        if(minutoinicio < 0)
            this.minutoinicio = 0;
        else if(minutoinicio >= 60)
            this.minutoinicio = 59;
        else
            this.minutoinicio = minutoinicio;
    }

    public void setHoraTermina(int horatermina){
        if(horatermina < 0)
            this.horatermina = 0;
        else if(horatermina > 24)
            this.horatermina = 24;
        else
            this.horatermina = horatermina;
    }

    public void setMinutoTermina(int minutotermina){
        if(minutotermina < 0)
            this.minutotermina = 0;
        else if(minutotermina >= 60)
            this.minutotermina = 59;
        else
            this.minutotermina = minutotermina;
    }

    public String getDias(){
        return dias;
    }

    public int getHoraInicio(){
        return horainicio;
    }

    public int getMinutoInicio(){
        return minutoinicio;
    }

    public int getHoraTermina(){
        return horatermina;
    }

    public int getMinutoTermina(){
        return minutotermina;
    }
}
