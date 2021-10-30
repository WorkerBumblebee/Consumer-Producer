#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>
 
int main()
{
        // Allocated shared memory and semaphore

                //Open am
        int shm_fd = shm_open("table", O_CREAT, 0666);
 
                //Create a mapping of a virtual adress space,
                //(default of 0 indicates) -
                //kernel decides where the mapping should be
                //the size of the mapping 32 bits (size of an int)
                //allow for other processes to read and write
                //the bits of the mapping
                //all updates in the mapping are shared between processes
                //starting at the first element (0)
        int *table = mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

                //Initialize the semaphores, each with a pointer to it,
                //with a specified "name",
                //created if not existing already,
                //all bits able to be read or written
                //and initialized with the intial value

                         //fill - indicates the current number of elements
                        //in the map, starts off as empty (0)
       	sem_t* fill = sem_open("fill", O_CREAT, 1666, 1);

                        //avail - indicates the number of spots remaning
                        //in the map, starts off as all (2)
        sem_t *avail = sem_open("available", O_CREAT, 0666, 2);
 
                        //mutex - a mutex semaphore, restricting access to the
                        //the map (critical section) to only ONE process at a time
                        //(mutual exclusion) - indicates the number of reserved
                        //spaces remaining for process (to enter the critical
                        //section) - MAX 1
        sem_t *mutex = sem_open("mutex", O_CREAT, 0666, 1);

       	// Here we wait until space is available in
        // the shared buffer. We then wait a random
        // number of ms, use mutual exclusion on
        // incrementing the table, and signaling
        // the fill semaphore for the consumer side
        // which will cause it to wait if there are
        // no items in the shared memory.

/*      int loop = 20;
        printf("\nProducer ready to create %d items.\n", loop);
printf("\nBeforep\n");

//      for(int i = 1; i < loop; ++i) {
//printf("\nInp\n");
//              sem_wait(avail);
//printf("ssdasd");
/*
               int ms = rand() % 2 + 1;
                sleep(ms);

/*              sem_wait(mutex);
//              ++(*table);
                printf("Item produced, there are now %d item(s) in the table.\n", *table);
                sem_post(mutex);
*/
                sem_post(fill);
/////   }

/*int i = 0;
while(sem_getvalue(fill, zero) !=0)
{
        sleep((rand() % 2));
        printf("%d\n", i);
        i++;
}
*/
  	//Close and unlink semaphores
        //Deallocate shared memory

//      sem_close(fill);
/*      sem_close(avail);
        sem_close(mutex);
        */
//      sem_unlink("fill");
/*      sem_unlink("available");
        sem_unlink("mutex");

        munmap(table, sizeof(int));

        close(tbl);
        shm_unlink("table");
*/
  	printf("Producer2 cleaned up!"); //*/
        return 0;
}
