#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
#include <vector>
#include <algorithm> // Para std::max

using namespace std;

// Función para verificar si un número es primo
bool es_primo(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Función para lanzar un dado de 6 caras
int lanzar_dado() {
    return rand() % 6 + 1;
}

// Función para lanzar dos dados y devolver la suma y los resultados individuales
void lanzar_dos_dados(int &dado1, int &dado2, int &suma) {
    dado1 = lanzar_dado();
    dado2 = lanzar_dado();
    suma = dado1 + dado2;
}

// Función para manejar el caso cuando el resultado es 12
int manejar_doce() {
    int resultado = 12;
    cout << "Sacaste un 12. Puedes decidir lanzar 1 dado para alcanzar hasta 18." << endl;
    int decision;
    cout << "Lanzar 1 dado (1 para sí, 0 para no): ";
    cin >> decision;
    if (decision == 1) {
        resultado += lanzar_dado();
    }
    return resultado;
}

// Función para manejar el caso cuando se sacan dobles
int manejar_dobles(int resultado) {
    cout << "¡Sacaste dobles! Puedes dividir el lanzamiento y lanzar 3 dados dos veces más." << endl;
    int suma_lanzamientos = resultado;
    for (int i = 0; i < 2; ++i) {
        cout << "Lanzamiento adicional " << (i + 1) << ":" << endl;
        int resultado_adicional = lanzar_dado() + lanzar_dado() + lanzar_dado();
        cout << "Resultado: " << resultado_adicional << endl;
        suma_lanzamientos += resultado_adicional;
    }
    return suma_lanzamientos;
}

// Función para obtener el mejor resultado cercano a 23, priorizando números primos
int obtener_mejor_resultado(int puntuacion) {
    vector<int> primos = {2, 3, 5, 7, 11, 13, 17, 19, 23}; // Lista de números primos menores o iguales a 23
    int mejor_resultado = puntuacion;
    if (puntuacion <= 23 && es_primo(puntuacion)) {
        return puntuacion;
    }
    for (int p : primos) {
        if (p <= 23 && p <= puntuacion) {
            mejor_resultado = max(mejor_resultado, p);
        }
    }
    return mejor_resultado;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Inicializa la semilla para el generador de números aleatorios

    int dado1, dado2, puntuacion;
    lanzar_dos_dados(dado1, dado2, puntuacion);
    cout << "Lanzaste dos dados. Resultado del dado 1: " << dado1 << ", Resultado del dado 2: " << dado2 << endl;
    cout << "Suma de los dos dados: " << puntuacion << endl;

    if (puntuacion == 12) {
        puntuacion = manejar_doce();
    }

    // Verificar si el resultado es un doble
    if (dado1 == dado2) {
        puntuacion = manejar_dobles(puntuacion);
    }

    int mejor_resultado = obtener_mejor_resultado(puntuacion);

    cout << "Puntuación final: " << puntuacion << endl;
    cout << "Mejor resultado cercano a 23 o número primo: " << mejor_resultado << endl;

    return 0;
}
