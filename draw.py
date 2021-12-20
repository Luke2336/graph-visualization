from matplotlib import collections
import matplotlib.pyplot as plt
import sys
import fruchterman_reingold

# input
n, m = map(int, input().split())
graph = []
for i in range(m):
  graph.append([int(i) for i in input().split()])
  assert(len(graph[i]) == 2)

coordinate = fruchterman_reingold.Visualization(n, m, graph)

x = []
y = []
for i in range(n):
  x.append(coordinate[i][0])
  y.append(coordinate[i][1])

segments = []
for edge in graph:
  u = edge[0]
  v = edge[1]
  segments.append([(x[u], y[u]), (x[v], y[v])])
  
collection = collections.LineCollection(segments, color=['red']*n)

fig, axes = plt.subplots(1, 1)
axes.add_collection(collection)
axes.scatter(x, y, s = 20)
for i in range(len(x)):
  axes.annotate(str(i), (x[i], y[i]))
axes.autoscale()

plt.show()