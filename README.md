# so_long

## Table of Contents
+ [About](#about)
+ [Getting Started](#getting_started)
+ [Usage](#usage)

## About
This project is a very small 2D game. Here I work with
textures, sprites and some basic gameplay elements.

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

This project works only on Linux/MacOS platforms only.
make sure to include the following frameworks for MacOS:
```
-framework OpenGL -framework AppKit
```

### Installing

To play you can use some of the makefile rules, or execute the file _so_long_ if it's been generated, passing the map you want to play as parameter (``./so_long ../TEST/maps/s.ber``). The make file has the following rules:

 + ``make`` -> Generates _so_long.out_ and an object file for each .c
 + ``make clean``  Deletes all object files
 + ``make fclean``  Deletes the object files and the _so_long_
 + ``make re``  makes ``fclean`` and ``make`` again 

## Usage

The game is able to play any map you want as long as it follow some specific rules:
* The map has to be a ``.ber`` file.
* It can only contain some of the following characters:

| 1 | Wall. |
| 0 | Empty space. |
| C | Collectable. |
| E | Exit. |
| P | Player starting position. |
* The map must be a rectangle surrounded by walls ‘1’.
* It must have at least one exit ‘E’ and one collectable ‘C’. And only one player ‘P’.

See some examples in the ``./TEST/maps`` folder of this project.
