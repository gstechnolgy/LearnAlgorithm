#include<stdio.h>

/*
 T1 -- [1,3]
 T2  --- [2,5]
 T3    __[4,6]
 T4      ___[6,9]

 Need to select the non over lapping time stamp
 checkOverLap() --> fmunction should give non overlapping time stamps
 sort based on the end time of the given interval
*/

struct Node {
  int x;
  int y;
};

void printNodes(struct Node Nodes[],int size) {
  int i=0;
  while(i<size) {
     printf("\t [%d, %d]",Nodes[i].x,Nodes[i].y);
     i++;
  }
  printf("\n");
}

void swapNodes(struct Node *Node1, struct Node *Node2) { 
   struct Node *temp;
   temp->x=Node1->x;
   temp->y=Node1->y;
   Node1->x=Node2->x;
   Node1->y=Node2->y;
   Node2->x=temp->x;
   Node2->y=temp->y;
}

void sortNodesByEndTime(struct Node *Nodes,int size) {
   printf("\n Size: %d\n",size);
   printNodes(Nodes,size);
   int i=0; // begin of the Nodes array
   for(i=0; i<size;i++) {
     int j=i+1;
     for(;j<size;j++) {
        printf("\n compare %d --> %d", Nodes[i].y,Nodes[j].y);
        if(Nodes[i].y >= Nodes[j].y) {
           printf("\n swap %d --> %d", Nodes[i].y,Nodes[j].y);
           swapNodes(&Nodes[i],&Nodes[j]);
           printNodes(Nodes,size);
        }
     }
   }
}

void nonOverLappingNodes(struct Node* Nodes, int size, struct Node* result, int* numOfNodes) {
  int i=0;
  int endTime = -1;
  for(;i<size;i++) {
     if(Nodes[i].x>= endTime) {
       result[*numOfNodes]=Nodes[i];
       endTime=Nodes[i].y;
       *numOfNodes=*numOfNodes+1;;
     }
  } 
}
int main() {
  struct Node Nodes[] = {{1,3},{4,6},{2,5},{6,9}};
  sortNodesByEndTime(Nodes,4);
  struct Node result[4];
  int numOfNodes=0;
  nonOverLappingNodes(Nodes,4,result,&numOfNodes); 
  printNodes(Nodes,numOfNodes);
  return 0;
}  
