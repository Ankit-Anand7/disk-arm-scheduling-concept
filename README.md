# disk-arm-scheduling-concept
Developed a disk scheduling program in C implementing First Come-First Serve (FCFS), Shortest Seek First (SSF), and Elevator (SCAN) algorithms to simulate disk arm motion.





#Introduction
-------------

I have written the program in C language.In this assignment, I have written a program which implements the given three disk arm scheduling algorithm. The set of requests for cylinders is provided either by the user or is generated randomly, it is up to user to choose how he wants to do that.



#Workload Generation
--------------------

The requests generation in my program has been left to user to choose upon prompt. Once user inputs his choice the First Come-First Serve (FCFS), Shortest Seek First (SSF) and the Elevator (LOOK) algorithms are implemented and total distance travelled is calculated.

I have declared a 'requests' array which stores the cylinders. The size of the array or the number of cylinders is asked in command prompt and user can give his/her choice.

The user also has to choose among user input of cylinder values or random generation of the same.

Then the cylinder values are stored in the 'requests' array.

The initial position of the disk arm is assumed to be 50.

For FCFS, implementation is simple and distance is calculated from 50 to index 0 element in 'requests' array and subsequently from index 0 to 1, 1 to 2 and so on and same simulation is printed too. The final total distance traversed is printed then.

For SSF, I have sorted the array and implemented the algorithm. In the case where two tracks are both equally as close to the current position, I have chosen the lower one to be selected. I have maintained two pointers to implement the algorithm. 

For LOOK, i have chosen the arm to move downwards from initial position, ie, 50 to lowest request value and from lowest request value to all the way down to 0 and then move upwards till the highest cylinder value.

The output is generated in the specified format.

All the instructions in the attached source file are complemented with comments for ease of understanding.
