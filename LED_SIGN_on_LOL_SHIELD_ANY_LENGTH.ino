#include "Charliplexing.h"
#include "Font.h"

#include "Arduino.h"

/*Insert text into quotes */
//char test[] = "Ask me about Hackerspaces    Ace Monster Toys    Oakland, CA.      www.acemonstertoys.org    Follow us on Twitter: @AMT";
//char test[] = "When we try to pick out anything by itself, we find it hitched to everything else in the universe. -John Muir";
char test[] = "We wish you a Merry Christmas and a Happy New Year! Love Linus, Keelan, Sutter, Decker, Frith & Sean";
//char test[] = "The machinery in this workshop have no brains.      Please use your own.    Ask for help if you need it.";
//char test[] = "Eat...   Sleep...  ROCK!!!   Repeat.    ";
int testLength = sizeof(test); //returns the length of the test[] string
int x = 0, x2 = 0;

void setup()
{
  LedSign::Init(); //initializes screen
}


void loop()
{
  
  for (int j = 13; j > -(6 * testLength); j--)/*chars are at most 5-6 pixels wide, so I used 6*testlength because j has to do with the length of the message in pixels*/
  {
    
    x = j;
    LedSign::Clear();
    for (int i = 0; i < testLength; i++)
    {
      
      x2 = Font::Draw(test[i], x, 0); //I believe this draws the char and saves the width to x2
      x += x2; //adding the new place on the x-axis to put the char
      if (x >= 13) break; /*if the length of what is on the scren is >=13, it starts over and goes to the next char*/
    }  
    delay(50);
  }
  
}


