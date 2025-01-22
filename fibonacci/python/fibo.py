# coding: utf-8
import numpy as np
import time

fibo_cache = np.zeros(10000000, int)
#print(fibo_cache)
def main():
    start = time.time()
    print(fibonacci_memo(92))
    end = time.time()
    print(f"Temps d'exécution : {end - start:.6f} secondes")

    #print(fibonacci_memo(400))

def fibonacci_memo(n: int) -> int:
    if fibo_cache[n] != 0:
        return fibo_cache[n]
    #print(f"calculating fibo indice : {n}")
    if n < 2:
        return n
    if n not in fibo_cache:
        fibo_cache[n] = fibonacci_memo(n-1) + fibonacci_memo(n-2)
    return fibo_cache[n]



if __name__ == "__main__":
    main()
