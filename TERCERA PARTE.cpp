
    int opcion;
    do {
        cout << "\n=== MENÚ PRINCIPAL ===\n";
        cout << "1. Listar productos con stock menor a 15\n";
        cout << "2. Listar todos los usuarios\n";
        cout << "3. Agregar producto al carrito\n";
        cout << "4. Ver carrito actual\n";
        cout << "5. Guardar carrito en archivo\n";
        cout << "6. Ver carrito guardado (archivo)\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: {
            vector<Producto> bajos = listarProductosBajoStock(productos);
            cout << "\n=== PRODUCTOS CON STOCK < 15 ===\n";
            for (size_t i = 0; i < bajos.size(); ++i)
                cout << bajos[i].id << " | " << bajos[i].nombre
                     << " | " << bajos[i].descripcion
                     << " | Precio: $" << bajos[i].precio
                     << " | Stock: " << bajos[i].stock << "\n";
            break;
        }
        case 2: {
            cout << "\n=== LISTA DE USUARIOS ===\n";
            for (size_t i = 0; i < usuarios.size(); ++i)
                cout << usuarios[i].id << " | " << usuarios[i].nombre
                     << " | " << usuarios[i].correo
                     << " | Dirección: " << usuarios[i].direccion
                     << " | Pago: " << usuarios[i].metodoPago << "\n";
            break;
        }
        case 3: {
            int idProd, cant;
            cout << "Ingrese el ID del producto: ";
            cin >> idProd;
            cout << "Cantidad: ";
            cin >> cant;
            cin.ignore();

            bool encontrado = false;
            for (size_t i = 0; i < productos.size(); ++i) {
                if (productos[i].id == idProd) {
                    ItemCarrito item;
                    item.producto = productos[i];
                    item.cantidad = cant;
                    carrito.push_back(item);
                    cout << "Producto agregado al carrito.\n";
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
                cout << "Producto no encontrado.\n";
            break;
        }
        case 4:
            mostrarCarrito(carrito);
            break;
        case 5:
            guardarCarritoArchivo(*usuarioActual, carrito);
            cout << "Carrito guardado correctamente en Carrito.txt.\n";
            break;
        case 6:
            mostrarCarritoArchivo();
            break;
        case 0:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opción no válida.\n";
        }
    } while (opcion != 0);

    return 0;
}
