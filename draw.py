from matplotlib import collections
import matplotlib.pyplot as plt
import sys

coordinate_file = open(sys.argv[2], 'r')
lines = coordinate_file.readlines()
coordinate_file.close()
n = len(lines)
x = []
y = []
for line in lines:
  a, b = line.split()
  x.append(int(a))
  y.append(int(b))

graph_file = open(sys.argv[1], 'r')
graph_file.readline()
lines = graph_file.readlines()
graph_file.close()
segments = []
for line in lines:
  a, b = line.split()
  u = int(a)
  v = int(b)
  segments.append([(x[u], y[u]), (x[v], y[v])])
  
collection = collections.LineCollection(segments, color=['red']*n)

fig, axes = plt.subplots(1, 1)
axes.add_collection(collection)
axes.scatter(x, y, s = 20)
for i in range(len(x)):
  axes.annotate(str(i), (x[i], y[i]))
axes.autoscale()

plt.savefig(sys.argv[3])
plt.show()