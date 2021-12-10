# include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
int board[8][8], column[8], d[15], b[15];

void print()
{ int i, j;
   for (i = 0; i<8; i++, cout<<endl)
             for (j = 0; j<8; j++)
                        if(!board[i][j])
                           {   //cout << board[i][j] <<"  ";
                                   cout << i << ", " << j <<"  ";
                             }
}

int safe(int i, int j)
{
        return  d[i+j] &&
                        b[7+j-i] &&
                        column[j] &&
                        board[i][j] ;
}


int Try(int i)
{ int j;
        for(j=0; j<8; j++)
         if(safe(i, j))
                { //Record
                   board[i][j] = d[i+j] = b[7+j-i] = column[j] = FALSE;
                   if (i==7)
                           return TRUE;
                   else if (Try(i+1))
                           return TRUE;
                   // Renove
           board[i][j]= d[i+j] = b[7+j-i] = column[j] = TRUE;
            }
         return false;
}


void initilize()
{ int i,j;
        for(i=0; i<8; i++)
            for(j=0; j<8; j++)
                  { d[i+j] = b[j-i+7] = TRUE;
                    board[i][j] = TRUE;}
        for(j=0; j<8;j++)
                column[j] = TRUE;
}
void main()
{       initilize();
        if (Try(0))
                print();
        else cout << "No solution";
}
