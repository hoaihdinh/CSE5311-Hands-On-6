import random

def gen_optimal_qsort_array(arr):
    if len(arr) == 1:
        return arr
    mid = len(arr) // 2

    # Assuming the pivot used is the last element in the array
    # The pivot goes in the middle, the subarrays are also optimal for the recursive calls of qsort
    return gen_optimal_qsort_array(arr[:mid]) + gen_optimal_qsort_array(arr[mid+1:]) + [arr[mid]]


n = [10, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]

# Uniform distributed arrays
for i in n:
    l = []
    for j in range(i):
        l.append(random.randint(0, 999))
    print(l)

# Worst case arrays
for i in n:
    print(range(i))

# Best case arrays (pivot goes right in the middle)
for i in n:
    print(gen_optimal_qsort_array(list(range(i))))
