# Задание 1.3

```py
def binary_search(mass: list) -> int:
    low, high = 0, len(mass) - 1
    while low <= high:
        mid = (low + high) // 2
        midVal = mass[mid]
        if low == high:
            return low if low + 1 > len(mass) - 1 - high else len(mass) - 1 - high
        if midVal > 0: high = mid - 1
        else: low = mid + 1
    return -1

mass = [-13, -12, -10, -8, -8, -3, -2, -1, 1, 3, 7, 9, 13, 16, 30]
print(binary_search(mass))
```