#run in terminal: python vishal/leet/70.py
def climbStairs(n):
    if n == 0 or n == 1:
        return 1

    a, b = 1, 1
    for i in range(2, n + 1):
        a, b = b, a + b

    return b


n = int(input("Enter the number of stairs: "))
print("Number of ways to climb the stairs:", climbStairs(n))
