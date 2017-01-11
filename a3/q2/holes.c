#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Process{
    char pName;
    int size;
    int swap;
} process;

typedef struct Queue{
    struct Process * pro;
    struct Queue * next;
    int start;
}queue;

int bit[128] = {0};

queue * createQueue(FILE*fp);
queue * createNode(char pName, int size, int n);
queue * addToBack(queue * head, queue * new);
queue * pop(queue * head);
void simulate(queue * ready, queue * save);
void firstFit(queue * ready);
void nextFit(queue * ready);
void bestFit(queue * ready);
void worstFit(queue * ready);
void userCheck();
void resetQueue(queue * ready, queue * save);

int main(int argv, char * argc[]){
    queue * head = NULL;
    queue * temp = NULL;
    queue * save = NULL;
    queue * new = NULL;
    FILE * file;    
    if(argv<2){
        printf("No input file.");
	exit(-1);
    }
    file = fopen(argc[1], "r");
    head = createQueue(file);
    temp = head;
    while(temp!=NULL){
        new = createNode(temp->pro->pName, temp->pro->size, 0);
        save = addToBack(save, new);
        temp = temp->next;
    }
    simulate(head, save);
    return(0);
}

queue * createQueue(FILE*fp){
    char buffer[50];
    queue * new = NULL;
    queue * head = NULL;
    int size = 0;
    char name;
    while(fgets(buffer, 80, fp)!=NULL){
        name = (strtok(buffer, " "))[0];
        size = atoi(strtok(NULL, "\n"));
        new = createNode(name, size, 0);
        head = addToBack(head, new);                  
    }
    fclose(fp);
    return(head);
}

queue * createNode(char pName, int size, int n){
    queue * tmp=NULL;
    tmp = malloc(sizeof(queue));
    if(tmp==NULL){
        printf("Could not allocate memory\n");
        exit(-1);
    }
    tmp->pro = malloc(sizeof(process));
    tmp->pro->pName = pName;
    tmp->pro->size = size;
    tmp->pro->swap = n;
    tmp->start = 0;
    tmp->next = NULL;
    return(tmp);
}

queue * addToBack(queue * head, queue * new){
    queue * curr;
    curr = head;
    if(head == NULL){
        return(new);
    }
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = new;
    new->next = NULL;
    return(head);
}

void simulate(queue * ready, queue * save){
    /*Run first fit sim*/
    system("reset");
    firstFit(ready);
    userCheck();
    resetQueue(ready, save);

    /*Run worst fit sim*/
    system("reset");
    worstFit(ready);
    userCheck();
    resetQueue(ready, save);

    /*Run best fit sim*/
    system("reset");
    bestFit(ready);
    userCheck();
    resetQueue(ready, save);
}

void firstFit(queue * ready){
    int a = 0;
    int largestHole = 0;
    int largestHoleAddress;
    int currentHole = 0;
    int totalHoles = 0;
    int numHoles = 0;
    int numLoads = 0;
    int numPro = 0;
    int totalPro = 0;
    int memUsed = 0;
    int i = 0;
    int fit = 0;
    int memory = 0;
    queue * new = NULL;
    queue * mem = NULL;
    printf("First Fit:\n******************************************\n");
    while(ready!=NULL){
       /*Check if there is enough memory*/
       for(i = 0; i<128; i++){
            if(bit[i]==0){
                a = i;
                if(i<128){
                    while(bit[i]==0 && i<128){
                        currentHole++;
                        i++;
                    }
                }
                numHoles++;
            }
            if(currentHole>=ready->pro->size && fit==0){
               largestHole = currentHole;
               largestHoleAddress = a;
               fit = 1;
            }
            currentHole=0;
            if(i<128){            
                memUsed++;
            }
        }
        printf("\nAttempting to load process:%c size:%d\n",ready->pro->pName, ready->pro->size);
        if(largestHole>=ready->pro->size){
            for(i=largestHoleAddress; i<(ready->pro->size+largestHoleAddress); i++){
                bit[i]=1;
                memUsed++;
            }
            new = createNode(ready->pro->pName, ready->pro->size, ready->pro->swap);
            new->start = largestHoleAddress; 
            mem = addToBack(mem, new);
            ready = pop(ready);
            numPro++;
            numLoads++;
            for(i = 0; i<128; i++){
               if(i%15==0){
                    printf("\n%d ", bit[i]);
               }
               else{
                    printf("%d ", bit[i]);
               } 
            }
            totalHoles+=numHoles;
            totalPro+=numPro;
            memory+=memUsed;
            printf("\n");
            printf("pid loaded, #processes = %d, #holes = %d, memusage = %.2f, cumulative mem = %.2f\n", numPro, numHoles, (double)((memUsed/1.28)), (double)(memory/numLoads));  
        }
        else{
           printf("Swapping process:%c starting Address:%d Ending Address:%d\n",mem->pro->pName ,mem->start, mem->start+mem->pro->size);
           for(i = mem->start; i<(mem->start+mem->pro->size); i++){
               bit[i]=0;
            }
            mem->pro->swap++;
            if(mem->pro->swap == 3){
                mem = pop(mem);
                numPro--;
            }
            else{
                new = createNode(mem->pro->pName, mem->pro->size, mem->pro->swap);
                ready = addToBack(ready, new);
                mem = pop(mem);
                numPro--;    
            }
        }
        currentHole = 0;
        largestHole = 0;
        largestHoleAddress = 0;
        numHoles = 0;
        memUsed = 0;
        fit = 0;
    }
    printf("\n******************************************\n");
    printf("First Fit ended:\n");
    printf("Total loads = %d, average #processes = %.2f, average #holes = %.2f, cumulative mem = %.2f\n\n", numLoads, (double)(totalPro/numLoads), (double)(totalHoles/numLoads), (double)(memory/numLoads));
}

queue * pop(queue * head){
    queue * temp;
    if(head!=NULL){
        temp = head;
        head = head->next;
        free(temp->pro);
        free(temp);
    }
    return head;
}

void userCheck(){
    printf("\n\nPress enter when ready for next simulation...\n\n");
    getchar();
}

void resetQueue(queue * ready, queue * save){
    int i;
    queue * new;
    queue * temp;
    temp = save;
    while(temp!=NULL){
        new = createNode(temp->pro->pName, temp->pro->size, 0);
        ready = addToBack(ready, new);
        temp = temp->next;
    }
    for(i = 0; i<128; i++){
        bit[i]=0;
    }
}

void worstFit(queue * ready){
 int a = 0;
    int largestHole = 0;
    int largestHoleAddress;
    int currentHole = 0;
    int totalHoles = 0;
    int numHoles = 0;
    int numLoads = 0;
    int numPro = 0;
    int totalPro = 0;
    int memUsed = 0;
    int i = 0;
    int memory = 0;
    queue * new = NULL;
    queue * mem = NULL;
    printf("Worst Fit:\n******************************************\n");
    while(ready!=NULL){
       /*Check if there is enough memory*/
       for(i = 0; i<128; i++){
            if(bit[i]==0){
                a = i;
                if(i<128){
                    while(bit[i]==0 && i<128){
                        currentHole++;
                        i++;
                    }
                }
                numHoles++;
            }
            if(currentHole>largestHole){
               largestHole = currentHole;
               largestHoleAddress = a;
            }
            currentHole=0;
            if(i<128){            
                memUsed++;
            }
        }
        printf("\nAttempting to load process:%c size:%d\n",ready->pro->pName, ready->pro->size);
        if(largestHole>=ready->pro->size){
            for(i=largestHoleAddress; i<(ready->pro->size+largestHoleAddress); i++){
                bit[i]=1;
                memUsed++;
            }
            new = createNode(ready->pro->pName, ready->pro->size, ready->pro->swap);
            new->start = largestHoleAddress; 
            mem = addToBack(mem, new);
            ready = pop(ready);
            numPro++;
            numLoads++;
            for(i = 0; i<128; i++){
               if(i%15==0){
                    printf("\n%d ", bit[i]);
               }
               else{
                    printf("%d ", bit[i]);
               } 
            }
            totalHoles+=numHoles;
            totalPro+=numPro;
            memory+=memUsed;
            printf("\n");
            printf("pid loaded, #processes = %d, #holes = %d, memusage = %.2f, cumulative mem = %.2f\n", numPro, numHoles, (double)((memUsed/1.28)), (double)(memory/numLoads));  
        }
        else{
           printf("Swapping process:%c starting Address:%d Ending Address:%d\n",mem->pro->pName ,mem->start, mem->start+mem->pro->size);
           for(i = mem->start; i<(mem->start+mem->pro->size); i++){
               bit[i]=0;
            }
            mem->pro->swap++;
            if(mem->pro->swap == 3){
                mem = pop(mem);
                numPro--;
            }
            else{
                new = createNode(mem->pro->pName, mem->pro->size, mem->pro->swap);
                ready = addToBack(ready, new);
                mem = pop(mem);
                numPro--;    
            }
        }
        currentHole = 0;
        largestHole = 0;
        largestHoleAddress = 0;
        numHoles = 0;
        memUsed = 0;
    }
    printf("\n******************************************\n");
    printf("Worst Fit ended:\n");
    printf("Total loads = %d, average #processes = %.2f, average #holes = %.2f, cumulative mem = %.2f\n\n", numLoads, (double)(totalPro/numLoads), (double)(totalHoles/numLoads), (double)(memory/numLoads));
}


void bestFit(queue * ready){
    int a = 0;
    int largestHole = 0;
    int largestHoleAddress;
    int currentHole = 0;
    int totalHoles = 0;
    int numHoles = 0;
    int numLoads = 0;
    int numPro = 0;
    int totalPro = 0;
    int memUsed = 0;
    int i = 0;
    int memory = 0;
    queue * new = NULL;
    queue * mem = NULL;
    printf("Best Fit:\n******************************************\n");
    while(ready!=NULL){
       /*Check if there is enough memory*/
       for(i = 0; i<128; i++){
            if(bit[i]==0){
                a = i;
                if(i<128){
                    while(bit[i]==0 && i<128){
                        currentHole++;
                        i++;
                    }
                }
                numHoles++;
            }
            if(largestHole==0){
                largestHole = currentHole;
            }
            if(currentHole<=largestHole && currentHole>=ready->pro->size && currentHole!=0){
               largestHole = currentHole;
               largestHoleAddress = a;
            }
            currentHole=0;
            if(i<128){            
                memUsed++;
            }
        }
        printf("\nAttempting to load process:%c size:%d\n",ready->pro->pName, ready->pro->size);
        if(largestHole>=ready->pro->size){
            for(i=largestHoleAddress; i<(ready->pro->size+largestHoleAddress); i++){
                bit[i]=1;
                memUsed++;
            }
            new = createNode(ready->pro->pName, ready->pro->size, ready->pro->swap);
            new->start = largestHoleAddress; 
            mem = addToBack(mem, new);
            ready = pop(ready);
            numPro++;
            numLoads++;
            for(i = 0; i<128; i++){
               if(i%15==0){
                    printf("\n%d ", bit[i]);
               }
               else{
                    printf("%d ", bit[i]);
               } 
            }
            totalHoles+=numHoles;
            totalPro+=numPro;
            memory+=memUsed;
            printf("\n");
            printf("pid loaded, #processes = %d, #holes = %d, memusage = %.2f, cumulative mem = %.2f\n", numPro, numHoles, (double)((memUsed/1.28)), (double)(memory/numLoads));  
        }
        else{
           printf("Swapping process:%c starting Address:%d Ending Address:%d\n",mem->pro->pName ,mem->start, mem->start+mem->pro->size);
           for(i = mem->start; i<(mem->start+mem->pro->size); i++){
               bit[i]=0;
            }
            mem->pro->swap++;
            if(mem->pro->swap == 3){
                mem = pop(mem);
                numPro--;
            }
            else{
                new = createNode(mem->pro->pName, mem->pro->size, mem->pro->swap);
                ready = addToBack(ready, new);
                mem = pop(mem);
                numPro--;    
            }
        }
        currentHole = 0;
        largestHole = 0;
        largestHoleAddress = 0;
        numHoles = 0;
        memUsed = 0;
    }
    printf("\n******************************************\n");
    printf("Best Fit ended:\n");
    printf("Total loads = %d, average #processes = %.2f, average #holes = %.2f, cumulative mem = %.2f\n\n", numLoads, (double)(totalPro/numLoads), (double)(totalHoles/numLoads), (double)(memory/numLoads));
}
