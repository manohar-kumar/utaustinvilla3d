params = []
values = []
with open("paramfiles/defaultParams.txt") as f:
	for line in f:
		line = line.strip().split()
		if len(line) == 0:
			continue
		if line[0][0] == '#' or line[0] == "//":
			continue
		params.append(line[0])
		values.append(line[1])

		# num1 = float(line)

for i in range(len(values)):
	print('"' + params[i] + '"' + ',')

for i in range(len(values)):
	print('"' + values[i] + '"' + ',')