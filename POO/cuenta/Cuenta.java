public class Cuenta{
    private float saldo;
    private String ncuenta;
    private String descripcion;

    public Cuenta(String cuenta, String desc){
        saldo = 0;
        ncuenta = cuenta;
        descripcion = desc;
    }

    public void abonar(float add){
        saldo += add;
    }

    public float obtenerSaldo(){
        return saldo;
    }
}
