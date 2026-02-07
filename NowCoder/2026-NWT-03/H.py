xa,ya = map(int, input().split())
xb,yb = map(int, input().split())

C = xa * yb - xb * ya
A = ya - yb

if A == 0:
    if abs(C) == 4:
        print(0.0)
    else:
        print("no answer")
else:
    ans = (4 - C) / A
    print(f"{ans:.10f}")