# LLD (Machine Coding Questions)
> **SNAKES AND LADDERS**
```
In the Snake and Ladder game implemented in C++ using object-oriented programming, there are several entities and their relationships.

1.  The Game class acts as the main controller of the game. It has a composition relationship with the Board, Player, Snake, and Ladder classes. The Game class contains an object of the Board class, an array of Player objects, an array of Snake objects, and an array of Ladder objects.  
    
2.  The Board class contains information about the game board, including player and snake/ladder positions. It has a relationship of association with the Player, Snake, and Ladder classes as it uses their attributes and methods to move players and check for snakes and ladders.  
    
3.  The Player class contains information about individual players, including their names and the number of moves. It has a relationship of association with the Board class as it uses the attributes and methods of the Board class to move the player on the board.  
    
4.  The Snake and Ladder classes contain information about the positions of snakes and ladders on the board, respectively. They have a relationship of association with the Board class as the Board class uses their attributes and methods to check for snakes and ladders on the board.
```
