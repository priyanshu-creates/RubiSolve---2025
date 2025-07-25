# rubiks-cube-solver
Rubik's Cube Solver Project for OOPS and DSA implementation

Use, below code to **compile** and generate a.exe
```
g++ main.cpp models/cube.cpp
```

**Run** using
```
a.exe
```
on the command prompt.

Alternatively you can use for **quick run**
```
run.bat
```
This can avoid providing inputs manually and directly run with arguments. <br />

The file "run.bat" can be editted for custom inputs. <br />

## Arguments
* Use integers 1 - 3 as first argument to select the cube model to use. 1 = Cube3d, 2 = Cube1d, 3 = Cubebit <br />
* Use integers 1 - 4 as second argument to select the solving algorithm. 1 = DFS, 2 = BFS, 3 = IDDFS, 4 = IDASTAR <br />
* Use any random integer to specify number of moves you want during random shuffle for the cube. <br />
* Use any random integer (preferably < 7 and definitely <= 20) to specify the search depth. <br />
