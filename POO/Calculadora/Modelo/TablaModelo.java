package Modelo;

import java.util.ArrayList;
import java.util.Vector;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

public class TablaModelo {
    public ArrayList listaEx = new ArrayList();
    
    public void agregarError(String clase, String archivo, String metodo, String linea){
        listaEx.add(new Excepcion(clase, archivo, metodo, linea));
    }
    
    public void eliminarError(int idx){
        listaEx.remove(idx);
    }
    
    public void inicializaTabla(JTable tabla){
        Vector titulos = new Vector();
        Vector<Vector <Object>> data = new Vector<Vector <Object>>();
        
        titulos.add("Clase");
        titulos.add("Archivo");
        titulos.add("Método");
        titulos.add("Línea");
        
        for(int i = 0; i < listaEx.size(); i++){
            Vector<Object> row = new Vector<Object>();
            
            row.add( ((Excepcion) listaEx.get(i)).getClase() );
            row.add( ((Excepcion) listaEx.get(i)).getArchivo() );
            row.add( ((Excepcion) listaEx.get(i)).getMetodo() );
            row.add( ((Excepcion) listaEx.get(i)).getLinea() );
            
            data.add(row);
        }
        
        DefaultTableModel modelo = new javax.swing.table.DefaultTableModel(data,titulos);
        this.establecerModeloJTable(modelo, tabla);
    }
    
    private void establecerModeloJTable(DefaultTableModel modelo, JTable tabla){
        tabla.setModel(modelo);
    }
}


