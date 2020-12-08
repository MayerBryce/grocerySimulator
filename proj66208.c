/* Project #6
   EGRE246 Fall 2019
   B. Mayer
   T. Glisan */

   #include <stdio.h>
   #include <stdlib.h>
   #include <stdbool.h>
   #include <time.h>
   #include "queue.h"
   #include "itemType.h"

   int main(void){

     //CREATE 5 LINES
     queue line1 = createQueue();
     queue line2 = createQueue();
     queue line3 = createQueue();
     queue line4 = createQueue();
     queue line5 = createQueue();

     //START OUT LINES WITH RANDOM ASSIGNED NUMBER OF PEOPLE (BETWEEN 1 & 5)
     int lineStart1 = rand() % ((5-1)+1)+1;
     printf("Line 1 starts with %d person(s)\n",lineStart1);
     int lineStart2 = rand() % ((5-1)+1)+1;
     printf("Line 2 starts with %d person(s)\n",lineStart2);
     int lineStart3 = rand() % ((5-1)+1)+1;
     printf("Line 3 starts with %d person(s)\n",lineStart3);
     int lineStart4 = rand() % ((5-1)+1)+1;
     printf("Line 4 starts with %d person(s)\n",lineStart4);
     int lineStart5 = rand() % ((5-1)+1)+1;
     printf("Line 5 starts with %d person(s)\n",lineStart5);
        //TIME TO CHECKOUT IS SOME RANDOM TIME BETWEEN 1 & 1O MINS
     int seed = 1;
     srand(seed);
     for(int start1 = 1; start1 <= lineStart1; start1++){
       enqueue(line1,rand() % ((10-1)+1)+1);
     }
     for(int start2 = 1; start2 <= lineStart2; start2++){
       enqueue(line2,rand() % ((10-1)+1)+1);
     }
     for(int start3 = 1; start3 <= lineStart3; start3++){
       enqueue(line3,rand() % ((10-1)+1)+1);
     }
     for(int start4 = 1; start4 <= lineStart4; start4++){
       enqueue(line4,rand() % ((10-1)+1)+1);
     }
     for(int start5 = 1; start5 <= lineStart5; start5++){
       enqueue(line5,rand() % ((10-1)+1)+1);
     }

    //CREATE A QUE THAT CUSTOMERS ENTER A LINE FROM
    queue lineEntry = createQueue();

    int startNumberOfCustomers = line1->count + line2->count + line3->count + line4->count + line5->count;

    //RANDOMLY ADD PEOPLE TO THE LINE ENTRY QUEUE (UP TO 'X' AMOUNT OF CUSTOMERS PER DAY)
    printf("Please enter the amount of customers you expect(between 25 and 100): ");
    int customerInput = 0, checkSize = 0, checkTime = 0, customerNumber = 0, run = 0;
    scanf("%d",&customerInput);
    for(int i = 0; i < (customerInput - startNumberOfCustomers); i++){
      enqueue(lineEntry,(rand() % ((10-1)+1)+1));
    }
    printf("Statistics are reported for every 5 customers and the last customer\n");
    while(run < customerInput){
    //DEQUEUE PEOPLE FROM LINES BASED ON TIME (CHECKOUT PROCESS)
    checkTime = front(line1);
    if(front(line2) < checkTime){
      checkTime = front(line2);
    }
    if(front(line3) < checkTime){
      checkTime = front(line3);
    }
    if(front(line4) < checkTime){
      checkTime = front(line4);
    }
    if(front(line5) < checkTime){
      checkTime = front(line5);
    }
    if(front(line1) == checkTime){
      customerNumber++;
      if(((customerNumber % 5) == 0) || (customerNumber == customerInput)){
        printf("Customer %d waited in line for %d minutes\n",customerNumber,checkTime);
      }
      dequeue(line1);
    }
    else if(front(line2) == checkTime){
      customerNumber++;
      if(((customerNumber % 5) == 0) || (customerNumber == customerInput)){
        printf("Customer %d waited in line for %d minutes\n",customerNumber,checkTime);
      }
      dequeue(line2);
    }
    else if(front(line3) == checkTime){
      customerNumber++;
      if(((customerNumber % 5) == 0) || (customerNumber == customerInput)){
        printf("Customer %d waited in line for %d minutes\n",customerNumber,checkTime);
      }
      dequeue(line3);
    }
    else if(front(line4) == checkTime){
      customerNumber++;
      if(((customerNumber % 5) == 0) || (customerNumber == customerInput)){
        printf("Customer %d waited in line for %d minutes\n",customerNumber,checkTime);
      }
      dequeue(line4);
    }
    else if(front(line5) == checkTime){
      customerNumber++;
      if(((customerNumber % 5) == 0) || (customerNumber == customerInput)){
        printf("Customer %d waited in line for %d minutes\n",customerNumber,checkTime);
      }
      dequeue(line5);
    }

    //ENQUEUE PEOPLE TO THE SHORTEST LINE BY CHECKING THE SIZE
        //FIND SMALLEST LINE
    checkSize = line1->count;
    if(line2->count < checkSize){
      checkSize = line2->count;
    }
    if(line3->count < checkSize){
      checkSize = line3->count;
    }
    if(line4->count < checkSize){
      checkSize = line4->count;
    }
    if(line5->count < checkSize){
      checkSize = line5->count;
    }

    if(checkSize == line1->count){
      enqueue(line1,front(lineEntry));
      dequeue(lineEntry);
    }
    else if(checkSize == line2->count){
      enqueue(line2,front(lineEntry));
      dequeue(lineEntry);
    }
    else if(checkSize == line3->count){
      enqueue(line3,front(lineEntry));
      dequeue(lineEntry);
    }
    else if(checkSize == line4->count){
      enqueue(line4,front(lineEntry));
      dequeue(lineEntry);
    }
    else if(checkSize == line5->count){
      enqueue(line5,front(lineEntry));
      dequeue(lineEntry);
    }
    run++;
  }
     return 0;
   }
