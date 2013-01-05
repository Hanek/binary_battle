#include "life.h"

 
void life::count(int x, int y)
{
  int xmin, xmax, ymin, ymax;
  int white_counter = 0;
  int black_counter = 0;
  
  xmin = (0 == x) ? fsize : 0;
  ymin = (0 == y) ? fsize : 0;
  xmax = (fsize-1 == x) ? -fsize : 0;
  ymax = (fsize-1 == y) ? -fsize : 0;
   
  
  if(ALIVE == population[x + 1 + xmax][y].state)
    {
     WHITE == population[x + 1 + xmax][y].race ? ++white_counter : ++black_counter ;
    }
    
  if(ALIVE == population[x - 1 + xmin][y].state)
    {
     WHITE == population[x - 1 + xmin][y].race ? ++white_counter : ++black_counter ;
    }
    
  if(ALIVE == population[x][y + 1 + ymax].state)
    {
     WHITE == population[x][y + 1 + ymax].race ? ++white_counter : ++black_counter ;
    }
    
  if(ALIVE == population[x][y - 1 + ymin].state)
    {
     WHITE == population[x][y - 1 + ymin].race ? ++white_counter : ++black_counter ;
    }
    
  if(ALIVE == population[x + 1 + xmax][y + 1 + ymax].state)
    {
     WHITE == population[x + 1 + xmax][y + 1 + ymax].race ? ++white_counter : ++black_counter ;
    }
    
  if(ALIVE == population[x + 1 + xmax][y - 1 + ymin].state)
    {
     WHITE == population[x + 1 + xmax][y - 1 + ymin].race ? ++white_counter : ++black_counter ;
    }
    
  if(ALIVE == population[x - 1 + xmin][y + 1 + ymax].state)
    {
      WHITE == population[x - 1 + xmin][y + 1 + ymax].race ? ++white_counter : ++black_counter ;
    }
    
  if(ALIVE == population[x - 1 + xmin][y - 1 + ymin].state)
    {
      WHITE == population[x - 1 + xmin][y - 1 + ymin].race ? ++white_counter : ++black_counter ;
    }
   
   
  population[x][y].nblack = black_counter;
  population[x][y].nwhite = white_counter;
}





