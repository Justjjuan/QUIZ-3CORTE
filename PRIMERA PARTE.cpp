#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Usuario {
    int id;
    string nombre;
    string correo;
    string contrasena;
    string direccion;
    string metodoPago;
};

struct Producto {
    int id;
    string nombre;
    string descripcion;
    double precio;
    int stock;
};

struct ItemCarrito {
    Producto producto;
    int cantidad;
};


int convertirEntero(const string &texto) {
    int valor = 0;
    stringstream ss(texto);
    ss >> valor;
    return valor;
}

double convertirDouble(const string &texto) {
    double valor = 0;
    stringstream ss(texto);
    ss >> valor;
    return valor;
}


vector<Usuario> cargarUsuarios(const string &nombreArchivo) {
    vector<Usuario> usuarios;
    ifstream archivo(nombreArchivo.c_str());
    string linea;
    getline(archivo, linea); 

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Usuario u;
        string idStr;
        getline(ss, idStr, ',');
        getline(ss, u.nombre, ',');
        getline(ss, u.correo, ',');
        getline(ss, u.contrasena, ',');
        getline(ss, u.direccion, ',');
        getline(ss, u.metodoPago, ',');
        u.id = convertirEntero(idStr);
        usuarios.push_back(u);
    }
    return usuarios;
}

vector<Producto> cargarProductos(const string &nombreArchivo) {
    vector<Producto> productos;
    ifstream archivo(nombreArchivo.c_str());
    string linea;
    getline(archivo, linea); 

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Producto p;
        string idStr, precioStr, stockStr;
        getline(ss, idStr, ',');
        getline(ss, p.nombre, ',');
        getline(ss, p.descripcion, ',');
        getline(ss, precioStr, ',');
        getline(ss, stockStr, ',');
        p.id = convertirEntero(idStr);
        p.precio = convertirDouble(precioStr);
        p.stock = convertirEntero(stockStr);
        productos.push_back(p);
    }
    return productos;
}


Usuario *iniciarSesion(vector<Usuario> &usuarios, const string &correo, const string &contrasena) {
    for (size_t i = 0; i < usuarios.size(); ++i)
        if (usuarios[i].correo == correo && usuarios[i].contrasena == contrasena)
            return &usuarios[i];
    return NULL;
}


vector<Producto> listarProductosBajoStock(const vector<Producto> &productos) {
    vector<Producto> bajos;
    for (size_t i = 0; i < productos.size(); ++i)
        if (productos[i].stock < 15)
            bajos.push_back(productos[i]);
    return bajos;
}

