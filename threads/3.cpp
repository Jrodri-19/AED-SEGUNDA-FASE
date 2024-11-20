#include <iostream>
#include <thread>
#include <vector>
#include <numeric>

void calcular_parcial(const std::vector<int> &datos, int inicio, int fin, int &resultado)
{
    resultado = std::accumulate(datos.begin() + inicio, datos.begin() + fin, 0);
}

int main()
{
    const std::vector<int> datos = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int resultado1 = 0, resultado2 = 0;

    // Crear hilos para calcular la suma parcial
    std::thread hilo1(calcular_parcial, std::ref(datos), 0, 5, std::ref(resultado1));
    std::thread hilo2(calcular_parcial, std::ref(datos), 5, 10, std::ref(resultado2));

    // Esperar a que terminen
    hilo1.join();
    hilo2.join();

    // Combinar resultados
    int suma_total = resultado1 + resultado2;

    std::cout << "La suma total es: " << suma_total << std::endl;
    return 0;
}
