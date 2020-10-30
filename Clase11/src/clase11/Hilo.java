/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clase11;

import static java.lang.Thread.sleep;
import java.util.logging.Level;
import java.util.logging.Logger;
import log.Lista_Servicios;

/**
 *
 * @author Andree
 */
public class Hilo extends Thread {

    int time = 0;

    @Override
    public void run() {
        while (true) {
            time = Lista_Servicios.time;
            if(Lista_Servicios.servicios.isEmpty())
                System.out.println("Se imprime cada "+time+" minuto");
            else{
                Lista_Servicios.GuardarBloque();
                //Lista_Servicios.servicios.clear();
                System.out.println("Se guardaron con exito");
            }
            esperarMinutos(time);
        }
    }

    private void esperarMinutos(int minutos) {
        try {
            sleep(minutos * 30000);//60000 indica un minuto
        } catch (InterruptedException ex) {
            Logger.getLogger(Hilo.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
