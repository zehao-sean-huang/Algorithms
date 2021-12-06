import copy

bit_array_to_int = lambda bits: eval("int(0b" + "".join(map(str, bits)) + ")")

def find_number(numbers, criteria_function):

    numbers_copy = copy.deepcopy(numbers)
    
    pos = 0
    while len(numbers_copy) > 1:
        criteria = criteria_function([bits[pos] for bits in numbers_copy])
        numbers_copy = list(filter(lambda bits: bits[pos] == criteria, numbers_copy))
        pos += 1

    return bit_array_to_int(numbers_copy[0])


if __name__ == "__main__":
    lines = open("day03.in").readlines()
    numbers = list(map(lambda line: [int(bit) for bit in line[:-1]], lines))

    n = len(numbers)

    most_frequent_bit = lambda bits: 1 if (sum(bits) >= (len(bits) // 2) if len(bits) % 2 == 0 else sum(bits) > (len(bits) // 2)) else 0
    least_frequent_bit = lambda bits: 1 - most_frequent_bit(bits)

    oxygen_rating = find_number(numbers, most_frequent_bit)
    co2_rating = find_number(numbers, least_frequent_bit)

    print(oxygen_rating, co2_rating)
    print(oxygen_rating * co2_rating)
