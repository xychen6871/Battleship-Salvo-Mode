# Battleship-Salvo-Mode

## Introduction

In this game of Battleship, the number of shots a player can fire is directly dependent on the number of ships the player has. For example, if a player has 5 ships remaining, then he/she can fire 5 shots. The number of shots a player can fire is decremented by 1 every time one of his/her ships is sunk. The game ends when one player has no ships remaining. 

## Ship Placement

When the game first boots, it tells both players to place their ships on the board. Player 1 would place his/her ships on the board. The ships are represented by the following characters:

- Carrier --> 'C', occupies 5 spaces.
- Battleship --> 'B', occupies 4 spaces.
- Destroyer --> 'D', occupies 3 spaces. 
- Submarine --> 'S', occupies 3 spaces.
- PT Boat --> 'P', occupies 2 spaces.

For every ship the player places on the board, the player needs to determine whether to place the ship horizontally or vertically and where to place the ship. The game will first ask the player this question:

Do you want the ship to be placed horizontally (1)? If not, the ship will be placed vertically (0).

The player will type the number 0 or 1 on the command prompt. If the number given is 0, the ship will be placed vertically. Otherwise the ship is placed horizontally. The game will then ask the player where to place the ship. The player responds by typing in two numbers on the command prompt. The first number represents the row and the second number represents the column. The player will be asked to try again if the spaces that would be occupied are either out of bounds or occupied by another ship. 

## The Battle

The battle starts when both players have finished placing their ships. At the beginning, both players start with 5 ships and thus can fire 5 shots at each other. Player 1 will always fire first, followed by Player 2. For each shot, the player is asked to enter two integers that represent the coordinate to be fired on. If the coordinate is outside the board or has already been fired on, the player will be asked to try again. Otherwise, the position is marked with either an 'X' or an 'O.' The 'X' represents a miss, while the 'O' represents a hit. The game will notify the attacking player if he or she managed to sink one of the other player's ships. Once the attacking player has fire all of his or her shots, the attacking player will end his/her turn. The other player would fire all of his/her shots and try to sink the other player's ships. When a player loses a ship, the number of shots a player can fire is decreased by one. Players keep taking turns firing at each other's ships until one player no longer has any ships remaining. 
