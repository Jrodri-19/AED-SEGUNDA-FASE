#include <iostream>
#include <thread>
#include <vector>

void tarea(int id) {
    std::cout << "Thread " << id << " ejecutándose." << std::endl;
}

int main() {
    std::vector<std::thread> hilos;

    // Crear 5 hilos
    for (int i = 0; i < 5; ++i) {
        hilos.emplace_back(tarea, i);
    }

    // Unir cada hilo al hilo principal
    for (auto& hilo : hilos) {
        hilo.join();
    }

    std::cout << "Todos los threads han terminado." << std::endl;
    return 0;
}
