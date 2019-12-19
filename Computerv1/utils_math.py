def ft_sqrt(nb):
    mn = 0
    mx = nb if nb >= 1 else 1
    while mx - mn > 0.000000001:
        mid = (mn + mx) / 2
        if mid * mid < nb:
            mn = mid
        else:
            mx = mid
    return mx