Basic usage 
  1) cd src
  2) g++ -o main.exe main.cpp graph.cpp
  3) ./main

Expected output: 
  ./main
Reading file: ../data/graph.txt
Read line: 1: 2, 3
Vertex: 1
Neighbor: 2
Neighbor: 3
Reading file: ../data/graph.txt
Read line:    2: 1, 3, 4
Vertex: 2
Neighbor: 1
Neighbor: 3
Neighbor: 4
Reading file: ../data/graph.txt
Read line:    3: 1, 2, 4
Vertex: 3
Neighbor: 1
Neighbor: 2
Neighbor: 4
Reading file: ../data/graph.txt
Read line:    4: 2, 3
Vertex: 4
Neighbor: 2
Neighbor: 3
Graph:
4: 2 3
3: 1 2 4
2: 1 3 4
1: 2 3
