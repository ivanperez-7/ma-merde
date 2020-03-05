package Modelo;

public class EmpleadoAsalariado extends Empleado{
    private double sueldoSemanal;

    public EmpleadoAsalariado(String nombre, String NSS, double sueldoSemanal){
        super(nombre, NSS);
        setSueldoSemanal(sueldoSemanal);
        obtenerIngresos();
    }

    public void setSueldoSemanal(double sueldoSemanal){
        if(sueldoSemanal <= 0)
            this.sueldoSemanal = 0;
        else
            this.sueldoSemanal = sueldoSemanal;
    }

    public double getSueldoSemanal(){
        return sueldoSemanal;
    }

    public void obtenerIngresos(){
        setIngresos(getSueldoSemanal());
    }

    public String toString(){
        return "Empleado asalariado\n" + super.toString() + "\nSueldo semanal: " + getSueldoSemanal();
    }
}
