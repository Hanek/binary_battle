#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

#ifndef _LIFE_H
#define _LIFE_H

#define ALIVE 1
#define DEAD  0
#define BLACK 1
#define WHITE 0

#define N_NEIGHBORS 8

#define DATAFILE "patterns/stable2.dat"
#define PFILE "pout.dat"



class life
{
  
public:

  class cell  
  {
  public:
  bool state;
  bool race;
  int  nblack;
  int  nwhite;
  
  cell(): state(DEAD), race(WHITE), nblack(0), nwhite(0) {}  
  };

  int fsize;
  int init_white;
  int init_black;
  vector<vector<cell> > population;
   
  void init(int field_size);
  void count(int x, int y);
  void createPatternRND();
  void loadPattern(const char* filename);
  void savePattern(const char* filename);
  void display(int i);
  bool evolve();
  void save_field_state(ofstream* file, int gen);
};
  
  

#endif