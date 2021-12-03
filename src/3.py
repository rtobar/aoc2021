import collections
import sys

def most_common_digit(numbers, position):
    counter = collections.Counter(n[position] for n in numbers)
    return counter['1'] - counter['0']

binary_numbers = list(line.strip() for line in sys.stdin)
digits = len(binary_numbers[0])

gamma = ''
for digit in range(digits):
    if most_common_digit(binary_numbers, digit) > 0:
        gamma += '0'
    else:
        gamma += '1'

gamma = int(gamma, 2)
epsilon = gamma ^ (2 ** digits - 1)
print(gamma)
print(epsilon)
print(gamma * epsilon)


def ogr(numbers, digits, least_common):
    candidates = list(numbers)
    for digit in range(digits):
        if least_common:
            if most_common_digit(candidates, digit) >= 0:
                matching_digit = '0'
            else:
                matching_digit = '1'
        else:
            if most_common_digit(candidates, digit) >= 0:
                matching_digit = '1'
            else:
                matching_digit = '0'
        candidates = [c for c in candidates if c[digit] == matching_digit]
        if len(candidates) == 1:
            return int(candidates[0], 2)
    raise ValueError

oxy = ogr(binary_numbers, digits, False)
co2 = ogr(binary_numbers, digits, True)
print(oxy)
print(co2)
print(oxy * co2)
