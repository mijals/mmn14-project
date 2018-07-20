char[] hoarders(char[] operand)
{
  if (operand == "r1")
    return "000001";
  if (operand == "r2")
    return "000010";
  if (operand == "r3")
    return "000011";
  if (operand == "r4")
    return "000100";
  if (operand == "r5")
    return "000101";
  if (operand == "r6")
    return "000110";  
  if (operand == "r7")
    return "000111";
  return "000000"
}
