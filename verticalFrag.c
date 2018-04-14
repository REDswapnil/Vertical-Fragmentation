#include<stdio.h>
int affinityMatrix[4][4] = {{55,0,15,40},
                             {0,45,45,0},
                               {15,45,55,0},
                               {40,0,0,40}};

 int attributeUsage[4][4] = {{0,1,1,0},
                                 {1,1,1,0},
                                 {1,0,0,1},
                                 {0,0,1,0}};

    int cost[4] = {30,15,40,10};


int flag;
void main(){
    int i,j;
    printf("Attribute usage matrix\n");
    for(i=0;i<4;i++)
    {
    for(j=0;j<4;j++)
    printf(" %d ",attributeUsage[i][j]);
    printf("\n");
    }

    printf("Cost For Each Query\n");
    for(i=0;i<4;i++)
    printf("Query 1 : %d \n",cost[i]);

    printf("Affinity matrix\n");
    for(i=0;i<4;i++)
    {
    for(j=0;j<4;j++)
    printf(" %d ",affinityMatrix[i][j]);
    printf("\n");
    }

    printf("Finding contribtions..\n");
    printf("Attribute 1 will be fixed as it is the primary key..");
    printf("Possible contributions are \n 1.(1,2,3) \n 2.(1,3,2) \n 3.(1,4,2)\n 4.(1,2,4)\n");

    printf("Finding contributions for all the possible combinations : \n");

    int contri1 = findContribution(1,2,3);
    int contri2 = findContribution(1,3,2);
    int contri3 = findContribution(1,4,2);
    int contri4 = findContribution(1,2,4);

    printf("CONTRIBUTIONS : \n");
    printf("1.(1,2,3) : %d \n 2.(1,3,2) : %d \n 3.(1,4,2) : %d \n 4.(1,2,4) : %d \n",contri1,contri2,contri3,contri4);

    //finding max contribution
    if((contri1>contri2)&&(contri1>contri3)&&(contri1>contri4))
    {
      printf("The maximum contribution will be from (1,2,3)");
       printf("Affinity matrix\n");
    for(i=0;i<4;i++)
    {
    for(j=0;j<4;j++)
    printf(" %d ",affinityMatrix[i][j]);
    printf("\n");
    }

    }

    if((contri2>contri1)&&(contri2>contri3)&&(contri2>contri4))
    {
      printf("The maximum contribution will be from (1,3,2)");
      int affinityMatrix2[4][4] = {{55,15,0,40},
                                   {0,45,45,0},
                                     {15,55,45,0},
                                     {40,0,0,40}};

         printf("Affinity matrix\n");
    for(i=0;i<4;i++)
    {
    for(j=0;j<4;j++)
    printf(" %d ",affinityMatrix2[i][j]);
    printf("\n");
    }

     int affinityMatrix2row[4][4] = {{55,15,0,40},
                                   {15,55,45,0},
                                     {0,45,45,0},
                                     {40,0,0,40}};


     printf("The corresponding matrix for row will be: \n");
       for(i=0;i<4;i++)
    {
    for(j=0;j<4;j++)
    printf(" %d ",affinityMatrix2row[i][j]);
    printf("\n");
    }
      flag =2 ;
    }

    if((contri3>contri1)&&(contri3>contri2)&&(contri3>contri4))
    {
      printf("The maximum contribution will be from (1,4,2)");
      int affinityMatrix3[4][4] = {{55,40,0,15},
                                   {0,0,45,45},
                                     {15,0,45,55},
                                     {40,40,0,0}};

         printf("Affinity matrix\n");
    for(i=0;i<4;i++)
    {
    for(j=0;j<4;j++)
    printf(" %d ",affinityMatrix3[i][j]);
    printf("\n");
    }
    }


    if((contri4>contri1)&&(contri4>contri2)&&(contri4>contri3))
    {
      printf("The maximum contribution will be from (1,2,4)\n");
      int affinityMatrix4[4][4] = {{55,0,40,15},
                                   {0,45,0,45},
                                     {15,45,0,55},
                                     {40,0,40,0}};

         printf("Affinity matrix\n");
    for(i=0;i<4;i++)
    {
    for(j=0;j<4;j++)
    printf(" %d ",affinityMatrix4[i][j]);
    printf("\n");
    }
    }

    if(flag ==2){
        printf("Fragments are:\n");
        printf("As the BEA suggested the configuration of (1,3,2,4), the fragments will be :\n 1.(1,3,2) \n 2.(1,4)\n");

    }









   // printf("%d",affinityMatrix[2][2]);
   //printf("%d\n",findBond(3,4));

    //printf("Permuting rows and columns of AA Matrix\n");


    //printf("%d\n",findContribution(2,4,3));

  }

int findBond(int a,int b)
  {
    //Assuming primary key to be Attribute 1
    int z=1,bond=0;
    while(z<4)
    {
      bond = bond + (affinityMatrix[a-1][z] * affinityMatrix[z][b-1]);
      z++;
    }

    return bond;
  }

int findContribution(int a,int b,int c)
{
    int contri = (2*findBond(a,b)) + (2*findBond(b,c)) - (2*findBond(a,c));
    return contri;
}
