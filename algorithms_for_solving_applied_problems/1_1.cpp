a, l, r = 0.2, 1, 2
while r - l > 0.0001:
    b = (l + r) / 2
    if (b ** 5 - b - a > 0): r=b
    else: l=b
    
print(b)
