/*1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 3 → 4 → 5 → 6 → 7 → 8 → 3
 Detect the loop in the given sll and find the element*/
#include <stdio.h>
#include<stdlib.h>
typedef struct s{
    unsigned int mem;
    struct s *next;
}sll;
sll *first=NULL,*last=NULL,*loop=NULL;
static int data=1;
void isloop();
void create(){
    
    
    sll *node=(sll*)malloc(sizeof(sll));/*creating the sll according to the question*/
    node->mem=data;
     node->next=NULL;
    if(first==NULL){
       
        first=last=node;
    }
    else{
        
        last->next=node;
        last=node;
    }
    if (data==3)
     loop=node;
     else if(data==8){
     node->next=loop;
     return;
     }
     data++;
     create();
     
}
void display_creator(){/*display the elements as created*/
    sll *disp=first;
    do{
        if((disp->mem==8)&&(disp->next->next->mem==4)){
        printf("%d:member\t",disp->mem);
        printf("\n%d:member loop repeat already known by creator\n",disp->next->mem);
        return;
    }
        else
        printf("%d:member\t",disp->mem);
        disp=disp->next;
    }while(1);
}   
void isloop(){/*detecting the loops*/

   sll *check_temp=first->next,*looper=first;/*can be optimized to 1 pointer*/
   int looped_element=0,loop_count=0,looper_element=0;/*detected repeaters are saved*/
   while(check_temp->mem>looper->mem){
       check_temp=check_temp->next;
       looper=looper->next;/*condition is if next member < current member , pattern fails and loop detected */
       if(looper->next->mem<looper->mem)
       looper_element=looper->mem;
   }
   looped_element=check_temp->mem;
   printf("%d is the looping element found by function\n",looped_element);
   printf("Loop in between %d and %d\n",looper_element,looped_element);
 
   do{
      loop_count++; 
     check_temp=check_temp->next;/*length of loop by traverse*/
   }while(check_temp->mem!=looped_element);
    printf("%d is length of loop calculated\n",loop_count);
   
}   
int main()
{
    create();
    display_creator();
   isloop();
    return 0;
}

