package Modelo;

public class Excepcion {
    private String clase;
    private String archivo;
    private String metodo;
    private String linea;

    public Excepcion(String clase, String archivo, String metodo, String linea) {
        this.clase = clase;
        this.archivo = archivo;
        this.metodo = metodo;
        this.linea = linea;
    }

    public String getClase() {
        return clase;
    }

    public String getArchivo() {
        return archivo;
    }

    public String getMetodo() {
        return metodo;
    }

    public String getLinea() {
        return linea;
    }
}
