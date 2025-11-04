void guardarCarritoArchivo(const Usuario &usuario, const vector<ItemCarrito> &carrito) {
    ofstream archivo("Carrito.txt", ios::app); 
    for (size_t i = 0; i < carrito.size(); ++i) {
        double subtotal = carrito[i].cantidad * carrito[i].producto.precio;
        archivo << usuario.id << ","
                << usuario.nombre << ","
                << carrito[i].producto.id << ","
                << carrito[i].producto.nombre << ","
                << carrito[i].cantidad << ","
                << carrito[i].producto.precio << ","
                << subtotal << "\n";
    }
    archivo.close();
}

void mostrarCarritoArchivo() {
    ifstream archivo("Carrito.txt");
    if (!archivo) {
        cout << "No hay carrito registrado.\n";
        return;
    }

    string linea;
    cout << "\n=== CONTENIDO DEL CARRITO GUARDADO ===\n";
    cout << "Usuario | Producto | Cantidad | Precio | Subtotal\n";
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string idUsuario, nombreUsuario, idProd, nombreProd, cantidad, precio, subtotal;
        getline(ss, idUsuario, ',');
        getline(ss, nombreUsuario, ',');
        getline(ss, idProd, ',');
        getline(ss, nombreProd, ',');
        getline(ss, cantidad, ',');
        getline(ss, precio, ',');
        getline(ss, subtotal, ',');
        cout << nombreUsuario << " | " << nombreProd << " | " << cantidad
             << " | $" << precio << " | $" << subtotal << "\n";
    }
    archivo.close();
}

void mostrarCarrito(const vector<ItemCarrito> &carrito) {
    cout << "\n=== CARRITO DE COMPRAS ===\n";
    double total = 0;
    for (size_t i = 0; i < carrito.size(); ++i) {
        double subtotal = carrito[i].cantidad * carrito[i].producto.precio;
        cout << carrito[i].producto.nombre
             << " (Precio: $" << carrito[i].producto.precio
             << ", Cantidad: " << carrito[i].cantidad
             << ") = $" << subtotal << "\n";
        total += subtotal;
    }
    cout << "TOTAL: $" << total << "\n";
}


int main() {
    vector<Usuario> usuarios = cargarUsuarios("Usuarios.txt");
    vector<Producto> productos = cargarProductos("Productos.txt");
    vector<ItemCarrito> carrito;

    string correo, contrasena;
    cout << "Correo electrónico: ";
    getline(cin, correo);
    cout << "Contraseña: ";
    getline(cin, contrasena);

    Usuario *usuarioActual = iniciarSesion(usuarios, correo, contrasena);
    if (!usuarioActual) {
        cout << "Usuario o contraseña inválidos.\n";
        return 0;
    }
