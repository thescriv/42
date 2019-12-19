import os
import sys
import re
from utils_math import ft_sqrt
from resolve import resolve_second_degrees, resolve_first_degrees, resolve_zero_degrees

def reduce_equation(a, b, c, degrees):
    reduced = 'Reduced form:'
    if degrees == 0 and c == 0:
        print("0 = 0")
        return 
    if c < 0:
        reduced += '-'
        c *= -1
    if c != 0:
        reduced += ' {} * X^0 '.format(c)
    if degrees >= 1 and b != 0:
        if b < 0 and degrees >= 1:
            reduced += '-'
            b *= -1
        else:
            reduced += '+'
        reduced += ' {} * X^1 '.format(b)
    if degrees == 2:
        if a < 0 and degrees == 2:
            reduced += '-'
            a *= -1
        else:
            reduced += '+'
        reduced += ' {} * X^2 '.format(a)
    reduced += "= 0"
    print(reduced)

def reduceEquation(index, part):
    index += 1
    a = 0
    b = 0
    c = 0

    for nb in part:
        nb, power = nb.split("*")
        x, power = power.split("^")
        power = float(power)
        nb = float(nb)
        if x != "X":
            return 
        if power == 2:
            a = nb
        elif power == 1:
            b = nb
        elif power == 0:
            c = nb
    return (index, a, b, c)

def parsing_equation(eqt):
    splited = eqt.replace(" ", "").replace("-", "+-").split("=")
    splited = [ list( filter(None, i.split("+")) ) for i in splited ]
    degrees = max( [ int(power.split("^")[1]) for power in splited[0] ] )

    a = 0
    b = 0
    c = 0
    index = 0

    for part in splited:
        index, aP, bP, cP = reduceEquation(index, part)
        if index == 1:
            a += aP
            b += bP
            c += cP
        else :
            a -= aP
            b -= bP
            c -= cP
    if degrees == 2 and a == 0:
        print("the number with the struct : [a * X^2] can't be equal to 0")
        return 
    reduce_equation(a, b, c, degrees)
    print("Polynomial degree: {:.0f}".format(degrees))
    if degrees > 2:
        print("The polynomial degree is stricly greater than 2, I can't solve.")
    if degrees == 2:
        resolve_second_degrees(a, b, c)
    elif degrees == 1:
        resolve_first_degrees(b, c)
    elif degrees == 0:
        resolve_zero_degrees(c)
    


def main():
    if len(sys.argv) == 2:
        equation = sys.argv[1]
        try:
            parsing_equation(equation)
        except:
            print("Error")
    else:
        while True:
            equation = input("Ecrive l'équation ici : ")
            try:
                parsing_equation(equation)
            except:
                print("Error")
            ext = input("Another one ? [Return/N]")
            if ext == 'N':
                break

if __name__ == '__main__':
	main()