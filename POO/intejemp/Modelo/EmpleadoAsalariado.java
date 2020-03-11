package Modelo;

public class EmpleadoAsalariado extends Empleado {
    private double salario;

    public EmpleadoAsalariado(String nombre, String NSS, double salario) {
        super(nombre, NSS);
        this.salario = salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public double getSalario() {
        return salario;
    }

    public double obtenerMontoPago() {
        return getSalario();
    }

    public String toString(){
        return "Emṕleado asalariado\n" + super.toString() + "\nSueldo: " + getSalario();
    }
}
