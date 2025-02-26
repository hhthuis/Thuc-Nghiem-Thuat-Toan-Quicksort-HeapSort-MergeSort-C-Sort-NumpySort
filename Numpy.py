import numpy as np
import time

def read_data(filename):
    data = []
    with open(filename, 'r') as file:
        lines = file.readlines()
        for line in lines:
            arr = list(map(float, line.split()))
            data.append(arr)
    return data

def sort(data):
    for i in range(len(data)):
        start = time.time()
        np.sort(data[i])  
        end = time.time()
        print(f"Numpy sort - Dãy {i+1}: {end - start:.5f} giây")


filename="input.txt"
data = read_data(filename)

sort(data)
