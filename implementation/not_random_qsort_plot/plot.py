import matplotlib.pyplot as plt

# Data from the qsort_output.txt
optimal = [0.000724, 0.003938, 0.008674, 0.013862, 0.027613, 0.025786, 0.041458, 0.06058, 0.072934, 0.078275, 0.086932]
worst = [0.000563, 0.01232, 0.043791, 0.108703, 0.1711, 0.257862, 0.373336, 0.498441, 0.700441, 0.986068, 1.22816]
uniform_rand = [0.000502, 0.006296, 0.013103, 0.017429, 0.024427, 0.035139, 0.040638, 0.072041, 0.052898, 0.053161, 0.063428]
size = [10, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]

plt.figure(figsize=(10, 5))
plt.plot(size, optimal, marker="o", linestyle="dashed", label="Optimal Array for Quicksort")
plt.plot(size, worst, marker="o", linestyle="dashed", label="Worst-Case Array for Quicksort")
plt.plot(size, uniform_rand, marker="o", linestyle="dashed", label="Uniformly Distributed Random Array for Quicksort")

plt.xlabel("Number of Elements")
plt.ylabel("Time (ms)")
plt.title("Quicksort Time vs n")
plt.grid(True)
plt.legend()

plt.show()