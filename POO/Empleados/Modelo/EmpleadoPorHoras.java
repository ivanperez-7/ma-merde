package Modelo;

public class EmpleadoPorHoras extends Empleado{
    private double sueldoBase;
    private int horas;

    public EmpleadoPorHoras(String nombre, String NSS, double sueldoBase, int horas){
        super(nombre, NSS);
        setSueldoBase(sueldoBase);
        setHoras(horas);
    }

    public void setSueldoBase(double sueldoBase){
        if(sueldoBase <= 0)
            this.sueldoBase = 0;
        else
            this.sueldoBase = sueldoBase;
    }

    public void setHoras(int horas){
        if(horas <= 0)
            this.horas = 0;
        else
            this.horas = horas;
    }

    public double getSueldoBase(){
        return sueldoBase;
    }

    public int getHoras(){
        return horas;
    }

    public void establecerIngresos(){
        if(horas <= 40)
            setIngresos(sueldoBase * horas);
        else if(horas > 40)
            setIngresos(40*sueldoBase + (horas-40)*sueldoBase*1.5);
    }

    public String toString(){
        return "Empleado por horas\n" + super.toString() + "\nSueldo por horas: " + getSueldoBase() + "\nHoras trabajadas: " + getHoras();
    }
}
