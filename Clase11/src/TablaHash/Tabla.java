/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TablaHash;

import java.util.ArrayList;

/**
 *
 * @author Andree
 */
public class Tabla {

    int tamaño = 5;
    Nodo[] tabla;
    double factorCarga = 0;
    int elementos = 0;

    public Tabla() {
        tabla = new Nodo[tamaño];
        for (int i = 0; i < tamaño; i++) {
            tabla[i] = null;
        }
        factorCarga = 0;
        elementos = 0;
    }

    public int getPosicion(int id) {
        int i = 0, p = 0;
        p = id % tamaño;
        while (tabla[p] != null) {
            i++;
            p = p + i;
            if (p > tamaño) {
                p = p - tamaño;
            }
        }
        return p;
    }

    public void insertar(int id, String llave, String valor) {
        Nodo nuevo = new Nodo(id, llave, valor);
        int posicion = getPosicion(id);
        tabla[posicion] = nuevo;
        elementos++;
        factorCarga = (double) elementos / tamaño;
        if (factorCarga > 0.75) {
            rehashing();
        }
    }

    private void rehashing() {
        int siguiente = tamaño;
        double factor = 0;
        do {
            siguiente = sigPrimo(siguiente);
            factor = (double) elementos / siguiente;
        } while (factor > 0.3);

        Nodo[] temporal = new Nodo[siguiente];
        for (int i = 0; i < siguiente; i++) {
            temporal[i] = null;
        }

        System.arraycopy(tabla, 0, temporal, 0, tamaño);
        tabla = temporal;
        tamaño = siguiente;
    }

    private int sigPrimo(int tam) {
        int a = 0;
        tam = tam + 1;
        for (int i = 1; i <= tam; i++) {
            if ((tam) % i == 0) {
                a++;
            }
        }
        if (a == 2) {
            return tam;
        } else {
            return sigPrimo(tam);
        }
    }

    public void print() {
        for (int i = 0; i < tamaño; i++) {
            if (tabla[i] != null) {
                System.out.printf("Indice: %d, hash: %d, Llave: %s, Valor: %s\n", i, tabla[i].hash, tabla[i].llave, tabla[i].valor);
            } else {
                System.out.printf("Indice: %d\n", i);
            }
        }
    }

    public double getFactorCarga() {
        return factorCarga;
    }

    public void setFactorCarga(double factorCarga) {
        this.factorCarga = factorCarga;
    }

}
