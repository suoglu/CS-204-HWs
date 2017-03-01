//Yigit Suoglu ~ 17720
//This file contains some function that works on string to convert it integer

#include "common.h"


//IMPORTANT_NOTE:functions below are designed to work with positive integers

bool isDigit(char ch, char & code)
//Takes a char input than compares it with the boundries of digit chars (e.g. '6')
{
    bool cond = ((ch >= '0') & (ch <= '9'));
    //return (((int)ch >= 48) & ((int)ch < 58)); //if not in range of digits return true
    if(cond)
    {return true;} //if input is between 0 and 9 return true
    code = ch; //save char if not digit
    return false;//and return false
}

bool isPosInteger(string str, char & code)
//searchs string for non digit char (e.g. '*', 'j')
{
    code = '0'; //set error code as no error
    for (int i = 0; i < str.length(); i++)
    //search every char of string untill find a non digit char
    {
      if(!isDigit(str[i], code))
      {
          if((i == 0) & (code == '-'))
          {
              code = '1'; //if data is negative
              continue; //ignore sign
          }
             return false; //if non digit found
      }

    }
    return code == '0'; //if all chars are digit, if data is negative
}

int simpleStrToInt(const string & str) //convert string to int. Note: input must be at unsigned integer format
{
    int target = 0; //to be returned
    for(int j = 0; j < str.length(); j++)
    {
        target *= 10; //go to next power
        int addition = ((int)str[j] - 48); //converts digit char to int
        target += addition; //add Converted value
    }

return target;
}

int strTOpint(string str, char & code)
//returns positive integer value of given string, gives an error if input is not a positive integer
{
  if(!isPosInteger(str, code)) //input check before conversion
  {
    cout << str << " is not a positive integer!\n";
    return -1;
  }

    return simpleStrToInt(str);
}

int strTOint(string str, char & code)
//returns integer value of given string, gives an error if input is not an integer
{
    bool cond = isPosInteger(str, code); //check if input is positive integer
    if(!cond) //if not pos. int.
    {
        if(code == '1') //if input is negative int
        {
            str[0] = '0'; //remove the sign
        }
        else //if not a digit return NULL
        {
           // cout << str << " is not an integer!\n";
            return NULL;
        }
    }
    int target = simpleStrToInt(str);
    
    if(code == '1') //fix sign after convertion
    {   target *= -1;
        code = '0';
    }
    
    return target;
    
}
