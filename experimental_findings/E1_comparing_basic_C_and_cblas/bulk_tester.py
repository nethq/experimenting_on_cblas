import os
import sys
import subprocess

for i in range(950,1000):
 os.system(f"./result.out {i} >> results.txt")
 print(i)
