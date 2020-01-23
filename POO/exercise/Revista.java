public class Revista{
    private String Nombre;
    private String ISSN;
    private int Anio;
    private String Editorial;

    public Revista(String nombre, String Issn, int anio, String editorial){
        Nombre = nombre;
        ISSN = Issn;
        Anio = anio;
        Editorial = editorial;
    }

    public void establecernombre(String nombre){        // métodos mutadores - cambian el estado del objeto
        Nombre = nombre;
    }

    public void establecerISSN(String Issn){
        ISSN = Issn;
    }

    public void estableceranio(int anio){
        Anio = anio;
    }

    public void establecereditorial(String editorial){
        Editorial = editorial;
    }

    public String obtenernombre(){
        return Nombre;
    }

    public String obtenerISSN(){
        return ISSN;
    }

    public int obteneranio(){
        return Anio;
    }

    public String obtenereditorial(){
        return Editorial;
    }

    public String imprimir(){
        return "Nombre: " + obtenernombre() + "\nISSN: " + obtenerISSN() + "\nAnio: " + obteneranio() + "\nEditorial: " + obtenereditorial();
    }
}
