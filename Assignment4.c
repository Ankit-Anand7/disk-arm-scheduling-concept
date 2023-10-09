// COEN 283 ASSIGNMENT 4
// ANKIT ANAND (W1652456)
// AANAND4@SCU.EDU


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



// First Come-First Serve (FCFS) algorithm
void fcfs(int *requests, int size) {
    int currentTrack = 50; //As assumed, initial arm position is 50
    int distance = 0;  //to keep track of total distance moved

    printf("First Come-First Serve Disk Arm Scheduling Algorithm\n\n");

    //A simple for loop calculates the distance in this case
    for (int i = 0; i < size; i++) {
        printf("Reading track %02d\t", requests[i]);
        printf("distance moved %02d\n", abs(requests[i] - currentTrack));
        distance += abs(requests[i] - currentTrack);
        currentTrack = requests[i];
    }

    printf("\nFCFS Total distance: %d\n\n", distance);
}

// Shortest Seek First (SSF) algorithm
void ssf(int *requests, int size) {
    int currentTrack = 50;  //As assumed, initial arm position is 50
    int distance = 0;       //to keep track of total distance moved

    printf("Shortest Seek First Disk Arm Scheduling Algorithm\n\n");

    // Sorts the requests array in ascending order
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (requests[j] < requests[i]) {
                int temp = requests[j];
                requests[j] = requests[i];
                requests[i] = temp;
            }
        }
    }

    int a=-1,b=-1;  //two pointers used for calculating shortest seek distance

    //If all the requests are greater than or equal to 50
    if(requests[0]>=currentTrack){
        b=0;
    }


    //loop to position the pointers in array such that 'a' points to request which is just smaller than 50, and 'b' points to request which is equal to or just greater than 50
    if(requests[size-1]<50){
        b=size;
        a=size-1;
    }
    else{
        for(int i=1;i<size;i++){
            if(currentTrack<requests[i]){
                a=i-1;
                b=i;
                break;
            }
        }
    }

    //loop to seek shortest distance till one of the pointer reaches the end/start of 'requests' array
    while(a>-1 && b<size){
        if(currentTrack-requests[a]>requests[b]-currentTrack){
            printf("Reading track %02d\t", requests[b]);
            printf("distance moved %02d\n",abs(requests[b]-currentTrack) );
            distance= distance+abs(requests[b]-currentTrack);
            currentTrack=requests[b];
            b++;

        }

        else{

            printf("Reading track %02d\t", requests[a]);
            printf("distance moved %02d\n",abs(currentTrack-requests[a] ));
            distance=distance+abs(currentTrack-requests[a]);
            currentTrack=requests[a];
            a--;
        }
    }


    //to seek distance of leftover requests
    while(a>-1){

        printf("Reading track %02d\t", requests[a]);
        printf("distance moved %02d\n",currentTrack-requests[a] );
        distance=distance+abs(currentTrack-requests[a]);
        currentTrack=requests[a];
        a--;
        
    }

    //to seek distance of leftover requests
    while(b<size){
        printf("Reading track %02d\t", requests[b]);
        printf("distance moved %02d\n",requests[b]-currentTrack );
        distance= distance+abs(requests[b]-currentTrack);
        currentTrack=requests[b];
        b++;

    }



    printf("\nSSF Total distance: %d\n\n", distance);
}




// Elevator (LOOK) algorithm
void look(int *requests, int size) {

    int currentTrack = 50;  //As assumed, initial arm position is 50
    int distance = 0;       //to keep track of total distance moved

    printf("Elevator (LOOK) Disk Arm Scheduling Algorithm\n\n");

    // Sorts the 'requests' array  in ascending order

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (requests[j] < requests[i]) {
                int temp = requests[j];
                requests[j] = requests[i];
                requests[i] = temp;
            }
        }
    }

    // Finds the index which is just bigger than or equal to 50, so that algorithm can start looking down from the index just before that

    int currentIndex = -1;  //to keep track of the index
    int j=-1;               //to keep track of the index to which look function will look from 0 while going up

    //loop to find currentIndex
    
    if(requests[size-1]<50){
        currentIndex=size-1;
        j=size;
    }
    else{
        for (int i = 0; i < size; i++) {
            if (requests[i] >= 50) {
                currentIndex = i;
                j=i;
                break;
            }
        }
    }

   


    // If all requests are smaller than 50
    if (currentIndex == -1) {
        currentIndex = 0;
        for (int i = 0; i < size; i++) {
            if (requests[i] > 50) {
                currentIndex = i;
                break;
            }
        }
    }

        

    //loop to move in downward direction till the lowest cylinder value in 'requests' array starting from 50

    for (int i = currentIndex - 1; i >= 0; i--) {
        printf("Reading track %02d\t", requests[i]);
        printf("distance moved %02d\n", abs(requests[i] - currentTrack));
        distance += abs(requests[i] - currentTrack);
        currentTrack = requests[i];
    }


    //to move the arm to all way down to zero
    
    printf("Reading track %02d\t", 0);
    printf("distance moved %02d\n", abs(currentTrack));
    distance +=currentTrack;
    currentTrack=0;

    
    //moves in upward direction till the highest cylinder value starting from 0

    for(int i=j;i<size;i++){
        printf("Reading track %02d\t", requests[i]);
        printf("distance moved %02d\n", abs(requests[i] - currentTrack));
        distance += abs(requests[i] - currentTrack);
        currentTrack = requests[i];

    }

    printf("\nLOOK Total distance: %d\n\n", distance);
}


int main() {

    // Seed the random number generator with the current time

    srand(time(NULL));

    int size; //defines the total number of cylinder values that user wants

    printf("Enter the number of requests: "); //Ask user to input the number of input he/she wants

    scanf("%d", &size);                        //User input in command line
    
    int *requests = (int*) malloc(size * sizeof(int)); //memory allocation
    
    int choice;  //to give user a choice to input manually of generate randomly

    printf("Choose 1 for random generation\nChoose 2 if you want to input cylinder numbers\n ");

    scanf("%d", &choice);


    //Switch-case to give user a choice to choose among random or user entered cylinder values
    switch (choice) {
        case 1:
        printf("\n\nCylinder values are generated randomly\n\n");
        for (int i = 0; i < size; i++) {
        requests[i]=rand()%100;  //for random cylinder values between 0 and 99
       
        }
        fcfs(requests, size);   //FCFS algorithm call
        ssf(requests, size);    //SSF algorithm call
        look(requests, size);   //LOOK algorithm call
        break;
            
        case 2:
        printf("\n\nInput cylinder numbers\n\n");
        for (int i = 0; i < size; i++) {

        scanf("%d",&requests[i]);   //for user input values

        }

        fcfs(requests, size);   //FCFS algorithm call
        ssf(requests, size);    //SSF algorithm call
        look(requests, size);   //LOOK algorithm call
        break;
       
        default:
        printf("Invalid choice.\nChoose among 1 or 2\n");
        break;
    }
    
    
   
    free(requests);         //frees memory
    
    return 0;
}
