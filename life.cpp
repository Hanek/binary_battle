#include "life.h"


/* use init() if you want pattern generated with createPatternRND() */

void life::init(int field_size)
{
  fsize = field_size;
  init_white = 0;
  init_black = 0;
  
  population.resize(fsize);
  
  for(int i = 0; i < fsize; ++i)
    population[i].resize(fsize, cell());
    
}


void life::createPatternRND()
{
  int x, y, init_width, beg, end;
  bool state;
  bool race;
  
  init_width = fsize/2 + 1; 
  beg = fsize/2 - init_width/2;
  end = fsize/2 + init_width/2;
   
  for(y = beg; y < end; ++y)
  {
    for(x = beg; x < end; ++x)
    {
      state = (0 == rand()%5) ? ALIVE : ALIVE;
       
      if(ALIVE == state)
         {
	   if(0 == rand()%2)
	   {race = BLACK; ++init_black;} 
	   else
	   {race = WHITE; ++init_white;}
	 }
      
      
     population[x][y].state = state; 
     population[x][y].race = race; 
    }
  }
}


void life::display(int i)
{
  int x, y;
  bool state, race;
  char cell_black[3] = "X ";
  char cell_white[3] = ". ";
  
  std::system("clear");
  cout << endl;
  
  for(y = 0; y < fsize; ++y)
  {    
    for(x = 0; x < fsize; ++x)
    {
      race  = population[x][y].race; 
      state = population[x][y].state;       
     (state == DEAD) ? cout << "  " : ((race == BLACK) ? cout << cell_black : cout << cell_white);
    }
    cout << "\n";
  }
   cout << "field size: " << fsize << "\ngeneration: " << i << "\ninit_black: " << init_black << " init_white " << init_white << "\n";
}




bool life::evolve()
{
  int x, y, nwhite, nblack, trace;
  bool state, race, vic;
  
  trace = -1;
  vic = true;
 
 /* populate cells and their neighbours */ 
 for(y = 0; y < fsize; ++y)
  {
    for(x = 0; x < fsize; ++x)
    { count(x, y); }
  } 
  
  
    
   
for(y = 0; y < fsize; ++y)
  {
    for(x = 0; x < fsize; ++x)
    { 
      state = population[x][y].state;
      
      if(ALIVE == state)
        {race  = population[x][y].race;
         if(-1 == trace)
           trace = race;}
      
      if(true == vic && trace != race)  
         vic = false;
      
      nwhite = population[x][y].nwhite;
      nblack = population[x][y].nblack;
      
      
      
          if(ALIVE == state)
            { 
	      if(N_NEIGHBORS-1 == nblack+nwhite)
		population[x][y].state = DEAD;
	      
	      if(N_NEIGHBORS-1 > nblack+nwhite && ((BLACK == race && nblack+1 < nwhite) || (WHITE == race && nwhite+1 < nblack)))
	      population[x][y].state = DEAD;
            }
            else
	    { 
	      if(nblack > nwhite)
	      {
		population[x][y].state = ALIVE;
		population[x][y].race = BLACK;
	      }
	      
		if(nblack < nwhite)
		{
		population[x][y].state = ALIVE;
		population[x][y].race = WHITE;
		}
            }
      trace = race;
    }
  }
  return vic;
}





void life::loadPattern(const char* filename)
{
  int x, y;
  char sym;
  ifstream file;
  file.open(filename); 
  
  file >> fsize;
  init(fsize);
  file >> init_black;
  file >> init_white;
  
  cout << fsize << " " << init_black << " " << init_white << endl;
  

  
  for(y = 0; y < fsize; ++y)
  {    
    for(x = 0; x < fsize; ++x)
    {
      file >> sym;

      if('X' == sym)
        {
	  population[x][y].state = ALIVE;
	  population[x][y].race = BLACK;
        }
         
      if('.' == sym)
        {
	  population[x][y].state = ALIVE;
	  population[x][y].race = WHITE;
        }
         
      if('-' == sym)
        {
	  population[x][y].state = DEAD;
	  population[x][y].race = WHITE;	  
	}
                
    } 

   }
file.close();   
}




void life::savePattern(const char* filename)
{
  int x, y;
  char sym;
  bool state, race;
  ofstream file;
  file.open(filename); 
  
  file << fsize << " ";
  file << init_black << " ";
  file << init_white  << endl;
  
  
  
  for(y = 0; y < fsize; ++y)
  {    
    for(x = 0; x < fsize; ++x)
    {
      
      state = population[x][y].state;   
      if(ALIVE == state)
      {
	race = population[x][y].race;
	sym = (BLACK == race) ? 'X' : '.' ;
      }
      else
	sym = '-';
      
      file << sym;
    }
    file << endl;  
   }
file.close();   
}





















