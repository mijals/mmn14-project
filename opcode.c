char[] opcode(char[] commend)
{
  if (commend == "cmp")
    return "0001";
  if (commend == "add")
    return "0010";
  if (commend == "sub")
    return "0011";
  if (commend == "not")
    return "0100";  
  if (commend == "clr")
    return "0101";
  if (commend == "lea")
    return "0110";
  if (commend == "inc")
    return "0111";
  if (commend == "dec")
    return "1000";  
  if (commend == "jmp")
    return "1001";
  if (commend == "bne")
    return "1010";
  if (commend == "red")
    return "1011";
  if (commend == "prn")
    return "1100";
  if (commend == "jsr")
    return "1101";
  if (commend == "rts")
    return "1110";
  if (commend == "stop")
    return "1111";
  return "0000";
}
