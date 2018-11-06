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
        
    default: return "wrong string!";
    }
  }

  
  //return stuff
  if (left > right) {return "Left side wins!";}
  else if (right > left) {return "Right side wins!";}
  else {return "Let's fight again!";}
  
}