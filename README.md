# Filler
## Project objective
 Writing a Filler player. 
 
Filler is an algorithmic game which consists in filling a grid of a known size in advance
with pieces of random size and shapes, without the pieces being stacked more than one
square above each other and without them exceeding the grid. If one of these conditions
is not met, the game stops.  

Each successfully placed piece yields a number of points, and has only one player, the
goal of the game could be to get the best score possible. However, it is with two players
that the filler takes all his interest. Each player has for the purpose of placing as many
pieces as possible while attempting to prevent his opponent from doing the same. At the
end of the game, the one with the most points wins the match...
## Skills to acquire and use
•	Fundamentals of C  
•	Algorithm elaboration  
•	Rigor  
•	Unix 
## How to run it? (works on MacOS)
•	git clone https://github.com/DaniilMD/Filler.git «Folder name»  
•	cd «Folder name»  
•	make  
•	Enter "resources_filler" folder
```
cd resources_filler/
```
* Launch the game using "filler_vm" and specifying the players and map. Like this:  
./filler_vm -p1 "player_1" -p2 "player_2" -v -f "map_to_play_on"  
  
For example:
```
./filler_vm -p1 players/abanlin.filler -p2 players/champely.filler -v -f maps/map00
```
Graphic visualization works only when there is an openelop.filler player:  
```
./filler_vm -p1 players/abanlin.filler -p2 ../openelop.filler -v -f maps/map00
```
## What does it do?
To be added...
## How it works
To be added...  
## Project evaluation result  
### Score 125/100  
Mandatory part  
100/100  
  
Bonus part  
25/25
  
Bonus funtionality:  
• A graphic visualizer.
