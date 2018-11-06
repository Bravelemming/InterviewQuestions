/*
Task
Write a function that accepts fight string consists of only small letters and return who wins the fight. When the left side wins return Left side wins!, when the right side wins return Right side wins!, in other case return Let's fight again!.

The left side letters and their power:
w - 4
p - 3
b - 2
s - 1
The right side letters and their power:
m - 4
q - 3
d - 2
z - 1
*/

#include <string>
using namespace std;

string alphabetWar(string fight)
{

  int left = 0;
  int right = 0;

  for (char x : fight)
  {
    switch (x)
    {
    case 'w': left += 4;
        break;
    case 'p': left += 3;
        break;
    case 'b': left += 2;
        break;
    case 's': left += 1;
        break;
    
    case 'm': right += 4;
        break;
    case 'q': right += 3;
        break;
    case 'd': right += 2;
        break;
    case 'z': right += 1;
        break;
        
    default: break;
    }
  }

  
  //return stuff
  if (left > right) {return "Left side wins!";}
  else if (right > left) {return "Right side wins!";}
  else {return "Let's fight again!";}
  
}
