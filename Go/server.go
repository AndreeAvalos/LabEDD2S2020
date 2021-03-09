package main

import(
	"encoding/json"
	"fmt"
	"github.com/gorilla/mux"
	"io/ioutil"
	"log"
	"net/http"
)
type Tienda struct {
	Nombre string `json: "Nombre, omitempty"`
	Descripcion string `json: "Descripcion, omitempty"`
	Contacto string `json: "Contacto, omitempty"`
	Calificacion int `json: "Calificacion, omitempty"`
}
type Departamento struct {
	Nombre string
	Tiendas []Tienda
}

type Dato struct {
	Indice string
	Departamentos []Departamento
}

type Sobre struct {
	Datos []Dato
}

func main() {
	request()
}

type Lst_Tiendas struct {
	Tiendas []Tienda
}


func homePage(w http.ResponseWriter, r *http.Request){
	fmt.Fprintf(w,"Servidor en Go")
}

func getArreglo(w http.ResponseWriter, r *http.Request)  {
	var lst_tiendas []Tienda
	
	lst_tiendas = append(lst_tiendas, Tienda{"Tienda1", "Esta es una tienda", "aavalosoto@gmail.com", 5})
	lst_tiendas = append(lst_tiendas, Tienda{"Tienda2", "Esta es una tienda", "aavalosoto@gmail.com", 5})
	lst_tiendas = append(lst_tiendas, Tienda{"Tienda3", "Esta es una tienda", "aavalosoto@gmail.com", 5})
	lst_tiendas = append(lst_tiendas, Tienda{"Tienda4", "Esta es una tienda", "aavalosoto@gmail.com", 5})
	lst_tiendas = append(lst_tiendas, Tienda{"Tienda5", "Esta es una tienda", "aavalosoto@gmail.com", 5})
	json1, _ := json.Marshal(lst_tiendas)
	fmt.Fprintf(w, string(json1))
}

func metodopost(w http.ResponseWriter, r *http.Request){
	body, _ := ioutil.ReadAll(r.Body)
	var re Sobre
	json.Unmarshal(body, &re)
	fmt.Println(re)
}

func request(){
	myrouter := mux.NewRouter().StrictSlash(true)
	myrouter.HandleFunc("/", homePage)
	myrouter.HandleFunc("/getArreglo",getArreglo).Methods("GET")
	myrouter.HandleFunc("/metodopost", metodopost).Methods("POST")
	log.Fatal(http.ListenAndServe(":3000", myrouter))
}
