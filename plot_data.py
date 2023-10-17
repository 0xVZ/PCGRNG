import matplotlib.pyplot as plt
import numpy as np

# Read random numbers from the file
with open("gauss_10mill.txt", "r") as file:
    random_numbers = [float(line.strip()) for line in file]

# Generate random colors for hexagons
colors = np.random.rand(len(random_numbers))

# Create a hexbin plot
plt.figure(figsize=(10, 8))
plt.hexbin(range(len(random_numbers)), random_numbers, gridsize=50, cmap='YlGnBu', edgecolors='gray', linewidth=0.2)
plt.colorbar(label='Count in Bin')
plt.title('PCG - pcg_gauss()')
plt.xlabel('Index')
plt.ylabel('Random Numbers')
plt.show()

plt.savefig("gauss_10mill.png")

# Read random numbers from the file
with open("rand_10mill.txt", "r") as file:
    random_numbers = [int(line.strip()) for line in file]

# Generate random colors for hexagons
colors = np.random.rand(len(random_numbers))

# Create a hexbin plot
plt.figure(figsize=(10, 8))
plt.hexbin(range(len(random_numbers)), random_numbers, gridsize=50, cmap='YlGnBu', edgecolors='gray', linewidth=0.2)
plt.colorbar(label='Count in Bin')
plt.title('PCG - pcg_rand()')
plt.xlabel('Index')
plt.ylabel('Random Numbers')
plt.show()

plt.savefig("rand_10mill.png")

# Read random numbers from the file
with open("randf_10mill.txt", "r") as file:
    random_numbers = [float(line.strip()) for line in file]

# Generate random colors for hexagons
colors = np.random.rand(len(random_numbers))

# Create a hexbin plot
plt.figure(figsize=(10, 8))
plt.hexbin(range(len(random_numbers)), random_numbers, gridsize=50, cmap='YlGnBu', edgecolors='gray', linewidth=0.2)
plt.colorbar(label='Count in Bin')
plt.title('PCG - pcg_randf()')
plt.xlabel('Index')
plt.ylabel('Random Numbers')
plt.show()

plt.savefig("randf_10mill.png")