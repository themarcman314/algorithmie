# coding: utf-8
import numpy as np
import time

bin_cache = np.zeros((500, 50), int)

def main():

    #start = time.time()
    #end = time.time()
    #print(f"Temps d'exécution : {end - start:.6f} secondes")


def coef_bino(n: int, k:int) -> int:
    if k > n:
        return 0
    if k == 0 and k == n:
        return 1


if __name__ == "__main__":
    main()
