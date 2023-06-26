# Path finder

The Path Finder is a project developed for the Algorithms and Data Structures university course.

(<center><img src="https://res.cloudinary.com/practicaldev/image/fetch/s--DHx-epgA--/c_imagga_scale,f_auto,fl_progressive,h_500,q_auto,w_1000/https://thepracticaldev.s3.amazonaws.com/i/9vj2bll4b6c31dqfqfdb.jpg" alt="drawing" width="600"/></center>

## Description

The Path finder is a maze with weighted entries (points) with the goal of finding either the best path (the one that leads to the maximum number of points) or the minimum path that leads to a positive number of points. 

The arguments that define each problem and are found in the first line of each .maps file are:
- dimensions of the matrix;
- minimum points to victory;
- initial position (agent);
- number of steps from the initial positions;
- starting points;

A .paths file is created to show the results and the path taken from the initial position.

The search is made recursively using a DFS (Depth First Search) approach and the current "best path" is saved in a dynamic stack with LIFO access.


## Getting Started


### Executing program

* To compile the program and in order to make things easier, there is a makefile;
*There's also a folder with test files: *.check and *.maps;
* From the command line, type:
```
make
```
* A .exe file will be created with the name "amazeme". Then, run:
```
./amazeme tests/<name_of_the_file.maps>
```
* A .paths file will be generated and can be compared to the corresponding .check to confirm that the optimal path has been found.
*Then, to clean whatever files have been created from the compilation, run:
```
make clean
```


## Authors

[@diogomoderno](https://www.linkedin.com/in/diogo-moderno-71335b156/)