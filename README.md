# Filler

A simple yet intriguing algorithmic project in C.

Two competing algorithms are placed on a board, and receive, turn by turn, 
a new piece given by a Virtual Machine. They can place this new piece anywhere, as
long as one of its tiles overlaps with one of the previous tiles placed of the player.

[Filler and its visualizer](/VisualizerFiller.png?raw=true "Screen shot of my filler.")


## About
This is the best filler program written at 42 school, no other player beats it yet
(as far as I know). Please contact me if you beat my player !

I also made a simple visualizer which represents the implementation of my algorithm.

### Usage

To launch filler with my player against "carli" use the following command :

```./resources/filler_vm -p1 ./resources/players/carli.filler-p2 ./the_legend_27.filler -f resources/maps/map02 ```

### Visualizer

Add ``` | visualisateur_filler/visualisateur``` at the end of your command.
To modify the filler visualizer size, modify X_SIZE and Y_SIZE in ./visualisateur_filler/includes/filler.h

