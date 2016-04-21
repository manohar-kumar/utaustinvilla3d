with open("start_out") as f:
	for line in f:
		num1 = float(line)

with open("end_out") as f:
	for line in f:
		num2 = float(line)

print(num2 - num1)