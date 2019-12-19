from utils_math import ft_sqrt

def resolve_second_degrees(a, b, c):
    delta = b**2 - 4 * a * c
    if delta > 0:
        print("Discriminant is strictly positive, the two solutions are:")
        sqrt_delta = ft_sqrt(delta)

        x1 = ((b*-1) - sqrt_delta) / (2 * a)
        x2 = ((b*-1) + sqrt_delta) / (2 * a)

        print('{:.6f}'.format(x1))
        print('{:.6f}'.format(x2))
    elif delta == 0:
        print("The solution is:")
        print(-(b / (2 * a)))
    elif delta < 0:
        step1 = 2 * a
        step2 = (b * -1) / step1
        step3 = (ft_sqrt(delta * -1) / step1)
        print('{} + {} * i'.format(round(step2, 6), round(step3, 6)))
        print('{} - {} * i'.format(round(step2, 6), round(step3, 6)))

def resolve_first_degrees(b, c):
    print("The solution is:")
    print(-c / b)

def resolve_zero_degrees(c):
    if (c == 0):
        print("All Solution are real")
    else:
        print(c)