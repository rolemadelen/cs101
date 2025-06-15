# File IO

## Writing to a file

```python
import os

file_path = f"{os.getcwd()}/data.dat"

with open(file_path, 'w+', encoding="utf-8") as f:
    f.write("Hello, World!\n")
```

## Reading from a file

```python
import os

file_path = f"{os.getcwd()}/data.dat"

with open(file_path, 'r+', encoding="utf-8") as f:
    lines = f.readlines() # read line by line

    for line in lines:
        print(line) # line.strip() to remove all the extra spaces
```

You can use `f.readlines()` to read line by line. If you want to reach each character, you can use `f.read()`.

For example, `f.readlines()` will return:
```text
["Hello, World!\n"]
```

On the other hand, `f.read()` will return:
```text
Hello, World!
```