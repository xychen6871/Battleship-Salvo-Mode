# Battleship-Salvo-Mode

## Introduction

In this game of Battleship, the number of shots a player can fire is directly dependent on the number of ships the player has. For example, if a player has 5 ships remaining, then he/she can fire 5 shots. The number of shots a player can fire is decremented by 1 every time one of his/her ships is sunk. The game ends when one player has no ships remaining. 

## Getting Started

When the game first boots, it tells both players to place their ships on the board. Player 1 would place his/her ships on the board. The ships are represented by the following characters:

- Carrier --> 'C', occupies 5 spaces.
- Battleship --> 'B', occupies 4 spaces.
- Destroyer --> 'D', occupies 3 spaces. 
- Submarine --> 'S', occupies 3 spaces.
- PT Boat --> 'P', occupies 2 spaces.

For every ship the player places on the board, the player needs to determine whether to place the ship horizontally or vertically and where to place the ship. The game will first ask the player this question:

Do you want the ship to be placed horizontally (1)? If not, the ship will be placed vertically (0).

The player will type the number 0 or 1 on the command prompt. If the number given is 0, the ship will be placed vertically. Otherwise the ship is placed horizontally. The game will then ask the player where to place the ship. The player responds by typing in two numbers on the command prompt. The first number represents the row and the second number represents the column. The player will be asked to try again if the spaces that would be occupied are either out of bounds or occupied by another ship. 
