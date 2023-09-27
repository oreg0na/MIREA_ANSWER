# Задание 1.1

```py
def binary_search(mass: list, key: int) -> int:
    low, high = 0, len(mass) - 1
    while low <= high:
        mid = (low + high) // 2
        midVal = mass[mid]
        if midVal == key: return mid
        if midVal > key: high = mid - 1
        else: low = mid + 1
    for i in range(len(mass)):
        if mass[i] < key and mass[i + 1] > key: 
            mass.insert(i + 1, key)
            return i
```