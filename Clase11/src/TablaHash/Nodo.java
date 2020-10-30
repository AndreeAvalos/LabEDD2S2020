/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TablaHash;

/**
 *
 * @author Andree
 */
public class Nodo {
    int hash;
    String llave;
    String valor;

    public Nodo(int indice, String llave, String valor) {
        this.hash = indice;
        this.llave = llave;
        this.valor = valor;
    }

    public int getHash() {
        return hash;
    }

    public void setHash(int hash) {
        this.hash = hash;
    }


    public String getLlave() {
        return llave;
    }

    public void setLlave(String llave) {
        this.llave = llave;
    }

    public String getValor() {
        return valor;
    }

    public void setValor(String valor) {
        this.valor = valor;
    }
    
}
