import os

file_path = f"{os.getcwd()}/data.dat"

with open(file_path, 'w+') as f:
    f.write("Nice to meet you!\n")

with open(file_path, 'r+') as f:
    lines = f.read()
    print(lines)
    