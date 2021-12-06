lines = open("day03.in").readlines()
numbers = list(map(lambda line: [int(bit) for bit in line[:-1]], lines))

n = len(numbers)
m = len(numbers[0])

most_frequent_bit = lambda bits: 1 if sum(bits) > (n // 2) else 0
least_frequent_bit = lambda bits: 1 - most_frequent_bit(bits)

epsilon = []
gamma = []

for i in range(m):
    epsilon.append(most_frequent_bit([bits[i] for bits in numbers]))
    gamma.append(least_frequent_bit([bits[i] for bits in numbers]))

bit_array_to_int = lambda bits: eval("int(0b" + "".join(map(str, bits)) + ")")

print(bit_array_to_int(epsilon), bit_array_to_int(gamma))
print(bit_array_to_int(epsilon) * bit_array_to_int(gamma))
