#include "bitwise_operations.h"
void Print(int set, char* setString){
bool emptyFlag = false;
if(set & (1 << 31))
{
    *(setString)='1';
    *(setString+1)='1';
    *(setString+2)='1';
    *(setString+3)='1';
    *(setString+4)='1';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 30))
{
    *(setString)='1';
    *(setString+1)='1';
    *(setString+2)='1';
    *(setString+3)='1';
    *(setString+4)='0';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;

}
if(set & (1 << 29))
{
   *(setString)='1';
    *(setString+1)='1';
    *(setString+2)='1';
    *(setString+3)='0';
    *(setString+4)='1';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;

}
if(set & (1 << 28))
{
   *(setString)='1';
    *(setString+1)='1';
    *(setString+2)='1';
    *(setString+3)='0';
    *(setString+4)='0';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 27))
{
  *(setString)='1';
    *(setString+1)='1';
    *(setString+2)='0';
    *(setString+3)='1';
    *(setString+4)='1';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 26))
{   
    *(setString)='1';
    *(setString+1)='1';
    *(setString+2)='0';
    *(setString+3)='1';
    *(setString+4)='0';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 25))
{
   *(setString)='1';
    *(setString+1)='1';
    *(setString+2)='0';
    *(setString+3)='0';
    *(setString+4)='1';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 24))
{
   *(setString)='1';
    *(setString+1)='1';
    *(setString+2)='0';
    *(setString+3)='0';
    *(setString+4)='0';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 23))
{
   *(setString)='1';
    *(setString+1)='0';
    *(setString+2)='1';
    *(setString+3)='1';
    *(setString+4)='1';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 22))
{
    *(setString)='1';
    *(setString+1)='0';
    *(setString+2)='1';
    *(setString+3)='1';
    *(setString+4)='0';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 21))
{
    *(setString)='1';
    *(setString+1)='0';
    *(setString+2)='1';
    *(setString+3)='0';
    *(setString+4)='1';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 20))
{
    *(setString)='1';
    *(setString+1)='0';
    *(setString+2)='1';
    *(setString+3)='0';
    *(setString+4)='0';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 19))
{
    *(setString)='1';
    *(setString+1)='0';
    *(setString+2)='0';
    *(setString+3)='1';
    *(setString+4)='1';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 18))
{
    *(setString)='1';
    *(setString+1)='0';
    *(setString+2)='0';
    *(setString+3)='1';
    *(setString+4)='0';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 17))
{
    *(setString)='1';
    *(setString+1)='0';
    *(setString+2)='0';
    *(setString+3)='0';
    *(setString+4)='1';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 16))
{   
    *(setString)='1';
    *(setString+1)='0';
    *(setString+2)='0';
    *(setString+3)='0';
    *(setString+4)='0';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 15))
{
   *(setString)='0';
    *(setString+1)='1';
    *(setString+2)='1';
    *(setString+3)='1';
    *(setString+4)='1';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 14))
{
    *(setString)='0';
    *(setString+1)='1';
    *(setString+2)='1';
    *(setString+3)='1';
    *(setString+4)='0';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 13))
{
    *(setString)='0';
    *(setString+1)='1';
    *(setString+2)='1';
    *(setString+3)='0';
    *(setString+4)='1';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 12))
{
    *(setString)='0';
    *(setString+1)='1';
    *(setString+2)='1';
    *(setString+3)='0';
    *(setString+4)='0';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 11))
{
    *(setString)='0';
    *(setString+1)='1';
    *(setString+2)='0';
    *(setString+3)='1';
    *(setString+4)='1';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 10))
{
    *(setString)='0';
    *(setString+1)='1';
    *(setString+2)='0';
    *(setString+3)='1';
    *(setString+4)='0';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 9))
{
    *(setString)='0';
    *(setString+1)='1';
    *(setString+2)='0';
    *(setString+3)='0';
    *(setString+4)='1';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 8))
{
    *(setString)='0';
    *(setString+1)='1';
    *(setString+2)='0';
    *(setString+3)='0';
    *(setString+4)='0';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 7))
{
    *(setString)='0';
    *(setString+1)='0';
    *(setString+2)='1';
    *(setString+3)='1';
    *(setString+4)='1';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 6))
{
    *(setString)='0';
    *(setString+1)='0';
    *(setString+2)='1';
    *(setString+3)='1';
    *(setString+4)='0';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 5))
{
    *(setString)='0';
    *(setString+1)='0';
    *(setString+2)='1';
    *(setString+3)='0';
    *(setString+4)='1';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 4))
{
    *(setString)='0';
    *(setString+1)='0';
    *(setString+2)='1';
    *(setString+3)='0';
    *(setString+4)='0';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 3))
{
    *(setString)='0';
    *(setString+1)='0';
    *(setString+2)='0';
    *(setString+3)='1';
    *(setString+4)='1';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 2))
{
    *(setString)='0';
    *(setString+1)='0';
    *(setString+2)='0';
    *(setString+3)='1';
    *(setString+4)='0';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & (1 << 1))
{
    *(setString)='0';
    *(setString+1)='0';
    *(setString+2)='0';
    *(setString+3)='0';
    *(setString+4)='1';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(set & 1)
{
    *(setString)='0';
    *(setString+1)='0';
    *(setString+2)='0';
    *(setString+3)='0';
    *(setString+4)='0';
    *(setString+5)=' ';
    setString = setString + 6;
    emptyFlag = true;
}
if(emptyFlag == false){
    *(setString)='e';
    *(setString+1)='m';
    *(setString+2)='p';
    *(setString+3)='t';
    *(setString+4)='y';
    setString = setString + 5;
}
*setString = '\0';
}
