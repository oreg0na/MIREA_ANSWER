def f(number: int) -> int:
    return number ** 5 - number - 0.2
x1, x2, x3 = 0, 16, 0
step = 0
esp = 0.0001
while 1:
    x3 = x1 - ( (x2 - x1) * f(x1) ) / (f(x2) - f(x1))
    if (abs(f(x3)) <= esp): break
    if (f(x3) < 0): x1 = x3
    else: x2 = x3
print(x3)