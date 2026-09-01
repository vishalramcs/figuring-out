# Run in terminal: python "vishal/leet/3622.py"
def checkDivisibility(n):
    digit_sum = 0
    product = 1
    temp = n

    while temp > 0:
        remainder = temp % 10
        digit_sum += remainder
        product *= remainder
        temp = temp // 10

    if n % (product + digit_sum) == 0:
        return True
    return False
n=int(input("Enter a number: "))
if checkDivisibility(n):
    print(f"{n} is divisible by the sum and product of its digits.")
else:                           
    print(f"{n} is not divisible by the sum and product of its digits.")    
