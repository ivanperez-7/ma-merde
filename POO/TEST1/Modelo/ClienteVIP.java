package Modelo;

public class ClienteVIP extends Cliente{
    private double costoDiario;

    public ClienteVIP(String clave, String nombre, Fecha ingreso, double costoDiario){
        super(clave, nombre, ingreso);
        setCostoDiario(costoDiario);
        super.setTipoCliente("Cliente VIP");
        super.setPagoPorDia(costoDiario);
    }

    public double getCostoDiario(){
        return costoDiario;
    }

    public void setCostoDiario(double costoDiario){
        if(costoDiario <= 0.0)
            this.costoDiario = 0.0;
        else
            this.costoDiario = costoDiario;
    }
}
