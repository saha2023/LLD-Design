
# LLD (Machine Coding Questions)
> **SNAKES AND LADDERS**
```
The followings are the functional requirements.

1.  The Game class acts as the main controller of the game. It has a composition relationship with the Board, Player, Snake, and Ladder classes. The Game class contains an object of the Board class, an array of Player objects, an array of Snake objects, and an array of Ladder objects.  
    
2.  The Board class contains information about the game board, including player and snake/ladder positions. It has a relationship of association with the Player, Snake, and Ladder classes as it uses their attributes and methods to move players and check for snakes and ladders.  
    
3.  The Player class contains information about individual players, including their names and the number of moves. It has a relationship of association with the Board class as it uses the attributes and methods of the Board class to move the player on the board.  
    
4.  The Snake and Ladder classes contain information about the positions of snakes and ladders on the board, respectively. They have a relationship of association with the Board class as the Board class uses their attributes and methods to check for snakes and ladders on the board.
```
<br><br>
> **PARKING LOT SYSTEM:** 
```
The following is a list of functional requirements for a parking lot system:

1) The parking lot system should be able to park cars, bikes, and handicapped vehicles.  
    
2) The system should be able to calculate the cost of parking for each type of vehicle.  
    
3) The system should be able to keep track of the time a vehicle is parked.  
    
4) The system should be able to remove a vehicle from a parking spot.  
    
5) The system should be able to check the availability of parking spots and handicapped spots on a specific floor.  
    
6) The system should be able to calculate the number of hours a vehicle has been parked.
```
<br><br>
> **FLIGHT  MANAGEMENT SYSTEM**
```
The following requirements are considered as functional requirements for an Airline Management System:

1.  Class Flight:  This class stores flight information such as flight number, departure city, arrival city, departure time, arrival time, flight status, and available seats. The class provides accessor functions to retrieve each piece of information.  
    
2.  Class Passenger: This class stores information about a passenger, such as name, booking status, and seat number. The class provides accessor functions to retrieve each piece of information.  
    
3.  Class Booking: This class stores information about a booking, such as booking number, passenger information, flight information, and payment details. The class provides accessor functions to retrieve each piece of information.  
    
4.  Class Staff: This class stores information about a staff member, such as name and staff ID. The class provides accessor functions to retrieve each piece of information.  
    
5.  Main Function: The main function creates objects of the classes and retrieves information about flight, passenger, booking, and staff using accessor functions. The retrieved information is displayed on the console.
```
