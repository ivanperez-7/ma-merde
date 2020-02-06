public class Depto{
    private String clave;
    private String nombre;

    public Depto(String clave, String nombre){
        this.clave = clave;
        this.nombre = nombre;
    }

    public void setClave(String clave){
        this.clave = clave;
    }

    public void setNombre(String nombre){
        this.nombre = nombre;
    }

    public String getClave(){
        return clave;
    }

    public String getNombre(){
        return nombre;
    }
}
