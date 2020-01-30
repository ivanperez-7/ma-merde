public class Empleado{
    private String clave;
    private String nombre;
    private String apellidoP;
    private String apellidoM;
    public Fecha nacimiento;

    public Empleado(String clave, String nombre, String apellidoP, String apellidoM, Fecha nacimiento){
        this.clave = clave;
        this.nombre = nombre;
        this.apellidoP = apellidoP;
        this.apellidoM = apellidoM;
        this.nacimiento = nacimiento;
    }

    public String getClave(){
        return clave;
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
