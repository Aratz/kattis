numbers = sorted([int(e) for e in input().split(" ,")])
print("vector<long long> rev_numbers {", end="")
for i in numbers[:-1]:
    print("{}, ".format(i), end="")
print("{}".format(numbers[-1]), end="")
print("};")
