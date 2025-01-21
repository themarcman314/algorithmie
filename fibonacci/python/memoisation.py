#coding: utf-8

# Import des biblioteque 
import time

# Fonction fibonacci

def fibonacci(n: int) -> int:
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fibonacci(n - 1) + fibonacci(n - 2)
   
def fibonacci_memo(n: int, memo: dict = {}) -> int:
    if n < 2:
        return n
    if n not in memo:
        memo[n] = fibonacci_memo(n-1, memo) + fibonacci_memo(n-2, memo)
    return memo[n]


# Instructions de tests

if __name__ == "__main__":
   
    start = time.time()
    res = fibonacci(40) # Calcule de Fibonacci
    end = time.time()
    print(f"Résultat : {res}")
    print(f"Temps d'exécution : {end - start:.6f} secondes")


    start = time.time()  
    result = fibonacci_memo(40)  # Calcul de Fibonacci 
    end = time.time()  
    print(f"Résultat : {result}")
    print(f"Temps d'exécution : {end - start:.6f} secondes")
