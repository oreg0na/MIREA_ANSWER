# Рабочая тетрадь 3, задание 1, яп: Python
def gn(array: list) -> int:
    if len(array) == 0:
        raise ValueError('Error')
    if len(array) == 1:
        return max(array[0])
    max_n = array[0]
    for i in range(len(array) - 2):
        max_n = max(array[0], array[1])
    return max_n
print(gn([4, 2, 3, 6, 9]))
