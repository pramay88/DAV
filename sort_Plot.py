import matplotlib.pyplot as plt

# Read data from the file
sizes = []
merge_times = []
quick_times = []

file = open("sorting_times.txt", "r") 
for line in file:
    size, merge_time, quick_time = map(float, line.split())
    sizes.append(int(size))
    merge_times.append(merge_time)
    quick_times.append(quick_time)

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(sizes, merge_times, label="Merge Sort", marker='.')
plt.plot(sizes, quick_times, label="Quick Sort", marker='.')
plt.xlabel('Input Size')
plt.ylabel('Time Taken (seconds)')
plt.title('Time Taken vs Input Size: Merge Sort vs Quick Sort')
plt.legend()
plt.grid(True)
plt.show()
