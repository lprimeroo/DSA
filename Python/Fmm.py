#Github username : yashvermac

# Fast Modulo Multipication calcaulates (a^b)%m in log(b) time
# It is based on the fact (a*b)%m = ((a%m)*(b%m))%m

def FastMultiplication(base, power, modulo):
    base = int(base)
    power = int(power)
    modulo = int(modulo)
    result = 1
    while power > 0:
        if power%2 != 0:
            result = (result * base) % modulo
        base = (base * base) % modulo
        power = power / 2
    return result

if __name__ == "__main__":
    base = raw_input("Enter base > ")
    power = raw_input("Enter power > ")
    modulo = raw_input("Enter modulo > ")
    print FastMultiplication(base, power, modulo)
