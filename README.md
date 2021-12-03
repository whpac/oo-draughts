# Draughts (OO version)

This is the draughts game. It supports only the console
interface.

## Compilation
The game requires no additional libraries for
compilation. The whole build chain is specified in
the makefile. Thus, it's sufficient to open the
terminal and type `make run` to compile and run the
game.

The makefile is OS-aware and was tested on Windows
and Ubuntu. The required compiler is `g++`, although
the code will probably be correctly compiled by other
tools.

## The game
By default, the board is 8x8 fields, but the size may
be specified as the only command-line argument to
the program. For example, `draughts.exe 6` will start
the game with a smaller, 6x6 board.

The controls are very classic, because the game
relies on commands. The basic and most important is:

```
m <from row> <from column> <to row> <to column>
```

The four parameters are the coordinates of the source
and destination fields. These can be read from the
bars along the top and left sides of the board.

Plan your moves carefully, because there is no way
to undo them!

To quit the game, type `q`, which stands for 'quit'.
There is also a command `h` that prints the help
in-game.

The game ends automatically when one of the players
loses their all pawns.