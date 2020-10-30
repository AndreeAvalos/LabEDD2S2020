/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clase11;

import log.Lista_Servicios;
import TablaHash.Tabla;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.json.simple.parser.JSONParser;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.ParseException;

/**
 *
 * @author Andree
 */
public class Clase11 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here

        Lista_Servicios lista = new Lista_Servicios();
        Comprobar();
        Interfaz interfaz = new Interfaz();
        interfaz.setVisible(true);
        Hilo t1 = new Hilo();
        t1.start();

        /*
        Tabla hashtable = new Tabla();
        hashtable.insertar(Lista_Servicios.ObtenerASCII("Miraflores"), "Miraflores", "Primero");
        hashtable.insertar(Lista_Servicios.ObtenerASCII("USAC"), "USAC", "segundo");
        hashtable.insertar(Lista_Servicios.ObtenerASCII("CINEPOLIS, MIRAFLORES"), "CINEPOLIS, MIRAFLORES", "tercero");
        hashtable.insertar(Lista_Servicios.ObtenerASCII("CAYALA"), "CAYALA", "HOLA ESTOY EN CAYALA");
        hashtable.insertar(Lista_Servicios.ObtenerASCII("PARQUE BARRONDO"), "PARQUE BARRONDO", "HOLA ME NOMBRARON ASI POR BARRONDO");
        hashtable.insertar(Lista_Servicios.ObtenerASCII("TIKAL FUTURA"), "TIKAL FUTURA", "HOLA ESTOY ABANDONADO");
        hashtable.insertar(Lista_Servicios.ObtenerASCII("COLISION"), "COLISION", "NO HAY COLISION");
        hashtable.insertar(Lista_Servicios.ObtenerASCII("NOISILOC"), "NOISILOC", "HAY COLISION");
        hashtable.print();
        System.out.println("Porcentaje de uso: " + hashtable.getFactorCarga());*/
    }
    private static FileReader fr = null;
    private static BufferedReader br = null;
    private static JSONParser parser = new JSONParser();

    private static void Comprobar() {
        String ruta = System.getProperty("user.dir");
        ruta += "\\bloque\\";
        //System.out.println(ruta);
        File carpeta = new File(ruta);
        File files[] = carpeta.listFiles();
        String cadena = "";
        int actual = 0;
        int anterior = 0;
        for (File file : files) {
            try {
                fr = new FileReader(file);
                br = new BufferedReader(fr);
                String linea;
                while ((linea = br.readLine()) != null) {
                    cadena += linea;
                }
                br.close();
                fr.close();
                JSONObject obj = (JSONObject) parser.parse(cadena);
                actual = Integer.parseInt(obj.get("anterior").toString());
                if (actual != anterior) {
                    System.out.println("La cadena en " + obj.get("id") + " se rompio");
                    System.out.println("No se guardaran los datos");
                    return;
                }
                Lista_Servicios.contador_id = Integer.parseInt(obj.get("id").toString());
                anterior = Integer.parseInt(obj.get("id").toString());
                cadena = "";
            } catch (FileNotFoundException ex) {
                Logger.getLogger(Clase11.class.getName()).log(Level.SEVERE, null, ex);
            } catch (IOException ex) {
                Logger.getLogger(Clase11.class.getName()).log(Level.SEVERE, null, ex);
            } catch (ParseException ex) {
                Logger.getLogger(Clase11.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

}
