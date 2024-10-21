import matplotlib.pyplot as plt
import numpy as np


y = np.array([500000, 900000, 1000000])

plt.figure(figsize=(8, 4))
plt.title("prime numbers (n) - parallel x sequential")
plt.xlabel("Time (s)")
plt.ylabel("Input size")

# parallel
x1 = np.array([11.0613, 33.7173, 41.0945])
plt.scatter(x1, y, c='red', label='parallel')

# sequential
x2 = np.array([42.9464, 132.859, 162.611])
plt.scatter(x2, y, c='green', label='sequential')

plt.legend(["Parallel", "Sequential"])

#plt.grid(True)

plt.xlim(0, 170)
plt.ylim(450000, 1050000)

plt.xticks(np.arange(0, 180, 20))

plt.savefig("pn.png")
plt.close()