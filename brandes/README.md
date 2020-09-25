# brandes
A implementation of Brandes' algorithm for calculating betweenness centrality in unweighted graphs.

## build
```bash
mkdir build
cd build
cmake ..
make
```
## run
```
./brandes input.txt output.txt
```
## example
Simple input:
```
0 1
1 0
1 2
2 1
2 3
3 2
3 0
0 3
1 3
```
Output:
```
0 0.5
1 1
2 0.5
3 1
```