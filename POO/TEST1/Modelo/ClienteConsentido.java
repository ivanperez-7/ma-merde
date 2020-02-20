package Modelo;

public class ClienteConsentido extends Cliente{
    private int rentasPorDia;
    private double precioPorRenta;

    public ClienteConsentido(String clave, String nombre, Fecha ingreso, int rentasPorDia, double precioPorRenta){
        super(clave, nombre, ingreso);
        setRentasPorDia(rentasPorDia);
        setPrecioPorRenta(precioPorRenta);
        super.setTipoCliente("Cliente Consentido");
        super.setPago(rentasPorDia * precioPorRenta);
    }

    public void setRentasPorDia(int rentasPorDia){
        if(rentasPorDia <= 0)
            this.rentasPorDia = 0;
        else
            this.rentasPorDia = rentasPorDia;
    }

    public void setPrecioPorRenta(double precioPorRenta){
        if(precioPorRenta <= 0.0)
            this.precioPorRenta = 0;
        else
            this.precioPorRenta = precioPorRenta;
    }

    public int getRentasPorDia(){
        return rentasPorDia;
    }

    public double getPrecioPorRenta(){
        return precioPorRenta;
    }
}
