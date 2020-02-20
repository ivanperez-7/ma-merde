package Modelo;

public class Cliente{
    private String clave;
    private String nombre;
    public Fecha fechaIngreso;
    private String tipoCliente;
    private double pagoPorDia;

    public Cliente(String clave, String nombre, Fecha fechaIngreso){
        this.clave = clave;
        this.nombre = nombre;
        this.fechaIngreso = fechaIngreso;
    }

    public void setClave(String clave){
        this.clave = clave;
    }

    public void setNombre(String nombre){
        this.nombre = nombre;
    }

    public void setFechaIngreso(Fecha fechaIngreso){
        this.fechaIngreso = fechaIngreso;
    }

    public void setTipoCliente(String tipoCliente){
        this.tipoCliente = tipoCliente;
    }

    public void setPagoPorDia(double pagoPorDia){
        this.pagoPorDia = pagoPorDia;
    }
   
    public String getClave(){
        return clave;
    }

    public String getNombre(){
        return nombre;
    }

    public String getTipoCliente(){
        return tipoCliente;
    }

    public double getPagoPorDia(){
        return pagoPorDia;
    }
}
