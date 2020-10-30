/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package log;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.json.simple.*;

/**
 *
 * @author Andree
 */
public class Lista_Servicios {

    public static ArrayList<String> servicios = new ArrayList<>();
    public static int time = 1;
    private static FileWriter archivo = null;
    private static PrintWriter pw;
    public static int contador_id = 1;
    public static String data = "";

    public static int ObtenerASCII(String cadena) {
        int suma = 0;
        for (char caracter : cadena.toCharArray()) {
            suma += (int) caracter;
        }
        return suma;
    }

    public static void GuardarBloque() {
        if (servicios.isEmpty()) {
            return;
        }
        try {
            Date fecha = new Date();
            String name = String.format("%d.%d.%d. %d-%d-%d", fecha.getHours(), fecha.getMinutes(), fecha.getSeconds(), fecha.getDay(), fecha.getMonth(), fecha.getYear());
            archivo = new FileWriter(".\\bloque\\"+name + ".txt");
            pw = new PrintWriter(archivo);
            JSONObject bloque = new JSONObject();
            bloque.put("id", contador_id);
            bloque.put("anterior", contador_id-1);
            contador_id++;
            bloque.put("name",name);
            servicios.forEach((servicio) -> {
                concatenar(servicio);
            });
            servicios.clear();
            bloque.put("data", data);
            pw.println(bloque);
            pw.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Lista_Servicios.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Lista_Servicios.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                if (null != archivo) {
                    archivo.close();
                }
            } catch (IOException e2) {

            }
        }
    }
    private static void concatenar(String servicio){
        data +=servicio+",\n";
    }
}
