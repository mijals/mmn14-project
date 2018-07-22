#include <string.h>

/*currently assuming correct input*/

int addressing(char[] operand)
{
  int i;
  if (operand[0] == '#')
    return 0;
  if (operand[0] == 'r' && opernd[1] >= 48 && operand[1] <= 55 && operand[2] == null)
    return 3;
  for(i=0; i<strlen(operand); i++)
    if (operand[i] == '(')
      return 2;
  return 1; 
}
