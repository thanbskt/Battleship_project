# Battleship_project
we developed a game to simulate the classic board game "battleship"


In order to cunstruct the game we use the classes:
tile: represents a shell of the board with variables X,Y as representing coordinates. Every shell has four types: ~ (sea), s (ship), X (Hit) and o (Miss).


ship: an abstract class that represents the ships. The ships are:
 Carrier -> 5 shells
 Battleship -> 4 shells
 Cruiser -> 3 shells
 Submarine -> 3 shells
 Destroyer -> 2 shells 

 Board: represents the board of every player consisting of multiple tiles

 Player: represents two players, player and computer.

 Main: represents the main class of the game. Ask player how to place ships and after that tha game starts. Its a turn based game that stops when one player doesn't have remaining ships.