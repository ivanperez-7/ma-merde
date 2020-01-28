public class Empleado{
    private String nEmpleado;
    private String nombre;
    private String apellidoP;
    private String apellidoM;
    private Fecha nacimiento;

    public Empleado(String nEmpleado, String nombre, String apellidoP, String apellidoM, Fecha nacimiento){
        this.nEmpleado = nEmpleado;
        this.nombre = nombre;
        this.apellidoP = apellidoP;
        this.apellidoM = apellidoM;
        this.nacimiento = nacimiento;
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
