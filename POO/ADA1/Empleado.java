public class Empleado{
    private String nEmpleado;
    private String nombre;
    private String apellidoP;
    private String apellidoM;
    Fecha nacimiento;

    public Empleado(String nEmpleado, String nombre, String apellidoP, String apellidoM, int dia, int mes, int anio){
        this.nEmpleado = nEmpleado;
        this.nombre = nombre;
        this.apellidoP = apellidoP;
        this.apellidoM = apellidoM;
        nacimiento = new Fecha(dia,mes,anio);
    }

    public String getNombre(){
        return nombre;
    }

    public String getApellidoP(){
        return apellidoP;
    }

    public String getApellidoM(){
        return apellidoM;
    }

    public String toString(){
        return getNombre() + " " + getApellidoP() + " " + getApellidoM();
    }
}
