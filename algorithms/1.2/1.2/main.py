def binary_search(mass: list, key: int) -> int:
    low, high = 0, len(mass) - 1
    while low <= high:
        mid = (low + high) // 2
        midVal = mass[mid]
        if midVal == key: return mid
        if midVal > key: high = mid - 1
        else: low = mid + 1
    return -1

def is_mountain(mass: list) -> bool:
    if len(mass) < 3: return False
    result = []
    for i in range(1, len(mass)):
        if mass[i - 1] < mass[i] > mass[i + 1]:
            result.append(mass[i])
    return result

mass = [1, 3, 2, 5, 9, 8]
isMountain = is_mountain(mass)
print(isMountain)