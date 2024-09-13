import random

def es_primo(num):
    """Verifica si un número es primo."""
    if num <= 1:
        return False
    if num <= 3:
        return True
    if num % 2 == 0 or num % 3 == 0:
        return False
    i = 5
    while i * i <= num:
        if num % i == 0 or num % (i + 2) == 0:
            return False
        i += 6
    return True

def lanzar_dado():
    """Lanza un dado de 6 lados y devuelve el resultado."""
    return random.randint(1, 6)

def lanzar_dos_dados():
    """Lanza dos dados y devuelve la suma de sus resultados y los resultados individuales."""
    dado1 = lanzar_dado()
    dado2 = lanzar_dado()
    suma = dado1 + dado2
    return dado1, dado2, suma

def manejar_doce():
    """Maneja el caso cuando el resultado es 12, permitiendo lanzar un dado adicional."""
    resultado = 12
    print("Sacaste un 12. Puedes decidir lanzar 1 dado para alcanzar hasta 18.")
    decision = int(input("Lanzar 1 dado (1 para sí, 0 para no): "))
    if decision == 1:
        resultado += lanzar_dado()
    return resultado

def manejar_dobles(resultado):
    """Maneja el caso cuando se sacan dobles, permitiendo lanzar 3 dados adicionales dos veces."""
    print("¡Sacaste dobles! Puedes dividir el lanzamiento y lanzar 3 dados dos veces más.")
    suma_lanzamientos = resultado
    for i in range(2):  # Dos veces para los dos lanzamientos adicionales
        print(f"Lanzamiento adicional {i + 1}:")
        resultado_adicional = lanzar_dado() + lanzar_dado() + lanzar_dado()
        print(f"Resultado: {resultado_adicional}")
        suma_lanzamientos += resultado_adicional
    return suma_lanzamientos

def obtener_mejor_resultado(puntuacion):
    """Obtiene el mejor resultado cercano a 23, priorizando números primos."""
    primos = [2, 3, 5, 7, 11, 13, 17, 19, 23]  # Lista de números primos menores o iguales a 23
    mejor_resultado = puntuacion
    if puntuacion <= 23 and es_primo(puntuacion):
        return puntuacion

    for p in primos:
        if p <= 23 and p <= puntuacion:
            mejor_resultado = max(mejor_resultado, p)

    return mejor_resultado

def main():
    random.seed()  # Inicializa la semilla para el generador de números aleatorios

    dado1, dado2, puntuacion = lanzar_dos_dados()
    print(f"Lanzaste dos dados. Resultado del dado 1: {dado1}, Resultado del dado 2: {dado2}")
    print(f"Suma de los dos dados: {puntuacion}")

    if puntuacion == 12:
        puntuacion = manejar_doce()

    # Verificar si el resultado es un doble (entre 2 y 12) y permite dividir el lanzamiento
    if dado1 == dado2:
        puntuacion = manejar_dobles(puntuacion)

    mejor_resultado = obtener_mejor_resultado(puntuacion)

    print(f"Puntuación final: {puntuacion}")
    print(f"Mejor resultado cercano a 23 o número primo: {mejor_resultado}")

if __name__ == "__main__":
    main()
