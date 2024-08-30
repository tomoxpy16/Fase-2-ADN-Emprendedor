// Fase 2: ADN Emprendedor | Aplicación para Administrar Tareas | Tomás Ospina Ulloa
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Tarea {
    string nombre;
    string categoria;
    string tipo;
};

vector<Tarea> tareas;

void crearTarea() {
    Tarea nuevaTarea;
    cout << "Nombre de la tarea: ";
    cin.ignore();  // Limpiar el buffer
    getline(cin, nuevaTarea.nombre);
    cout << "Prioridad (Alta, Media, Baja): ";
    getline(cin, nuevaTarea.categoria);
    cout << "Tipo (Trabajo, Academico, Otros): ";
    getline(cin, nuevaTarea.tipo);
    tareas.push_back(nuevaTarea);
    cout << "Tarea añadida.\n";
}

void eliminarTarea() {
    string nombreTarea;
    cout << "Nombre de la tarea a eliminar: ";
    cin.ignore();  // Limpiar el buffer
    getline(cin, nombreTarea);

    for (size_t i = 0; i < tareas.size(); ++i) {
        if (tareas[i].nombre == nombreTarea) {
            tareas.erase(tareas.begin() + i);
            cout << "Tarea eliminada.\n";
            return;
        }
    }
    cout << "No se encontró la tarea.\n";
}

void moverTarea() {
    string nombreTarea;
    cout << "Nombre de la tarea a mover: ";
    cin.ignore();  // Limpiar el buffer
    getline(cin, nombreTarea);

    for (size_t i = 0; i < tareas.size(); ++i) {
        if (tareas[i].nombre == nombreTarea) {
            cout << "Nueva prioridad (Alta, Media, Baja): ";
            getline(cin, tareas[i].categoria);
            cout << "Tarea movida.\n";
            return;
        }
    }
    cout << "No se encontró la tarea.\n";
}

void mostrarTareas() {
    cout << "\nTareas:\n";
    for (size_t i = 0; i < tareas.size(); ++i) {
        cout << "Tarea #" << i + 1 << "\n";
        cout << "Nombre: " << tareas[i].nombre << "\n";
        cout << "Prioridad: " << tareas[i].categoria << "\n";
        cout << "Tipo: " << tareas[i].tipo << "\n\n";
    }
}

int main() {
    int opcion;
    cout << "Bienvenid@ al Administrador de Tareas\n";
    do {
        cout << "\n--- ADMINISTRADOR DE TAREAS ---\n";
        cout << "1. Añadir Tarea\n";
        cout << "2. Eliminar Tarea\n";
        cout << "3. Cambiar Prioridad de una Tarea\n";
        cout << "4. Ver Todas las Tareas\n";
        cout << "5. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearTarea();
                break;
            case 2:
                eliminarTarea();
                break;
            case 3:
                moverTarea();
                break;
            case 4:
                mostrarTareas();
                break;
            case 5:
                cout << "Saliendo del Administrador\n";
                break;
            default:
                cout << "Opción no válida.\n";
        }
    } while (opcion != 5);

    return 0;
}
