import java.util.ArrayList;

public class Empleado{
    private String clave;
    private String nombre;
    private String apellidoPaterno;
    private String apellidoMaterno;
    public Fecha nacimiento;
    public Fecha ingreso;
    public Depto depto;
    private ArrayList<Horario> horario;

    public Empleado(String clave, String nombre, String apellidoPaterno, String apellidoMaterno, Fecha nacimiento, Fecha ingreso, Depto depto, ArrayList<Horario> horario){
        this.clave = clave;
        this.nombre = nombre;
        this.apellidoPaterno = apellidoPaterno;
        this.apellidoMaterno = apellidoMaterno;
        this.nacimiento = nacimiento;
        this.ingreso = ingreso;
        this.depto = depto;
        this.horario = horario;
    }

    public String getClave(){
        return clave;
    }

    public String getNombre(){
        return nombre;
    }

    public String getApellidoPaterno(){
        return apellidoPaterno;
    }

    public String getApellidoMaterno(){
        return apellidoMaterno;
    }

    public Horario getHorario(int i){
        return horario.get(i);
    }

    public int getSizeHorario(){
        return horario.size();
    }
}
