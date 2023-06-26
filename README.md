# Path finder

The Path Finder is a project developed for the Algorithms and Data Structures university course.

## Description

The Path finder is a maze with weighted entries (points) with the goal of finding either the best path (the one that leads to the maximum number of points) or the minimum path that leads to a positive number of points. 

The arguments that define each problem and are found in the first line of each .maps file are:
- dimensions of the matrix;
- minimum points to victory;
- initial position (agent);
- number of steps from the initial positions;
- starting points;

A .paths file is created to show the results and the path taken from the initial position.

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

Contributors names and contact info

ex. [@diogomoderno] (https://www.linkedin.com/in/diogo-moderno-71335b156/)