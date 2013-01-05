#include "life.h"

int main()
{
  srand (time(NULL));
  unsigned long int gen = 0;
  bool vic = false;
  life pop;
  
//      pop.init(13);
//      pop.createPatternRND();
//      pop.savePattern(PFILE);
   
     pop.loadPattern(DATAFILE);
  
   while(!vic)
  {
   vic = pop.evolve();
   pop.display(++gen); 
  }
  
  cout << "\nlast generation: " << gen << endl;
}





