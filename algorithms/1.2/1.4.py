nums = [5, 2, 6, 1]
result = []

for i in range(len(nums)):
    result.append(sum([1 if nums[i] > nums[j] else 0 for j in range(i + 1, len(nums))]))

print(result)
