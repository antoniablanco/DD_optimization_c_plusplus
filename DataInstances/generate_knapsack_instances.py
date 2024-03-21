import random

seed_value = 1
random.seed(seed_value)
variables_length = 500
max_variable_value = 50

right_side = 0
matrix_of_weights = []
for j in range(variables_length):
    value = random.randint(1, max_variable_value)
    right_side += value
    matrix_of_weights.append(value)

if right_side == 0:
    right_side_of_restrictions = 0
else:
    right_side_of_restrictions = right_side // 2

objective_weights = []
for j in range(variables_length):
    value = random.randint(1, max_variable_value)
    objective_weights.append(value)

width = variables_length//2

folder = 'DataInstances/txt/'
file_name = 'knapsack_instance_v' + str(variables_length) + '_d' + str(max_variable_value)+ '_seed'+str(seed_value)+'.txt'

with open(folder + file_name, 'w') as file:
    file.write(str(variables_length) + '\n')
    file.write(str(right_side_of_restrictions) + '\n') 
    file.write(str(width) + '\n')
    file.write(' '.join(map(str, matrix_of_weights)) + '\n')
    file.write(' '.join(map(str, objective_weights)) + '\n')