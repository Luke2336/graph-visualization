# Graph Visualization

## Introduction

This tool can be used to visualize an undirected simple graph.

The algorithm is based on a force-directed method and simulated annealing, called Fruchterman-Reingold.

#### Reference

-   https://dcc.fceia.unr.edu.ar/sites/default/files/uploads/materias/fruchterman.pdf

## Run

1.   Please install `matplotlib` first.
2.   Run the bash script.

```shell
./visualization.sh [InputFile] [OutputCoordinationFile] [OutputImageFile]
```

For example

```shell
./visualization.sh benchmark/input1.txt output1.txt output1.png
```

#### Input Format

The first line should contain two integer $n$ and $m$, where $n$ should less than 1000.

In $2 \sim m + 1$ lines, each line should contain two integer $a$ and $b$, where $0 \le a, b < n$.

```
n m
a1 b1
a2 b2
...
am bm
```

## Result
| id | type | image |
|:---:|:---:|:---:|
| 1 | $C_3$ | ![](./image/1.png) |
| 2 | $K_4$ | ![](./image/2.png) |
| 3 | Petersen Graph | ![](./image/3.png) |
| 4 | $K_{3,3}$ | ![](./image/4.png) |
| 5 | Tree | ![](./image/5.png) |
| 6 | Bamboo | ![](./image/6.png) |
| 7 | $K_5$ | ![](./image/9.png) |
| 8 | 100 isolated nodes | ![](./image/10.png) |
| 9 | Grid | ![](./image/12.png) |
| 10 | Caterpillar tree | ![](./image/13.png) |
| 11 | $C_{200}$ | ![](./image/15.png) |

