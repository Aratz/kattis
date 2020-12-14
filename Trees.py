N = int(input())
trees = sorted([int(i) for i in input().split()],key=lambda x:-x)
print(max([2+i+tree for i,tree in enumerate(trees)]))
