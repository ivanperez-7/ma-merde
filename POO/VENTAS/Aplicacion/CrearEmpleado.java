package Aplicacion;

import Modelo.*;

public class CrearEmpleado{
    public static void main(String[] args){
        EmpleadoPorComision ejemplo = new EmpleadoPorComision("15004196","ivan","perez","maldonado",0.10,2010.0);
        EmpleadoBasePorComision ejemplo2 = new EmpleadoBasePorComision("15004196","ivan","perez","maldonado",0.10,2010.0,110.0);
    }
}
