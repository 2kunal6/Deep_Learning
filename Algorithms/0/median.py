import sys

# read first line: length of vector
first_line = sys.stdin.readline()
n = int(first_line)

numbers = []

# read numbers
for line in sys.stdin:
    numbers.append(int(line))

# sort numbers =)
sorted_numbers = sorted(numbers)

# output median
if n%2==0:
    print("{:.1f}".format( (sorted_numbers[int(n/2)-1] + sorted_numbers[int(n/2)])/2 ))
else:
    print("{}".format(sorted_numbers[int(n/2)]))
