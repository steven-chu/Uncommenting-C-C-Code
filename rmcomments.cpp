// Quick note: This does code does not work completely as it doesn't know how to deal with string literal cases. If I figure it out, I'll come back and add on.

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

enum { normal, slash, comment, slashSatr, doubleSlash } condition = normal; // Defining different states/cases
int main()
{
char c;
  while(scanf("%c", &c) > 0) { // While loop that reads characters from input stream. 
    switch(condition) { // The switch(condition) means switch the state depending if it satisfies the cases.
      case normal: // Normal is the default case.
        if (c == '/') { // If it detects '/', the condition is changed to slash.
         condition = slash; 
        } else if (c == '"') { // Checks whether the current character is '"'.
         printf("%c", c); // Print the current character which is the double quote.
         condition = normal;
        } else {
         printf("%c", c); // Continue printing from input stream.
         break;
         
      case slash:
        if (c == '*') { // Detects whether an asterisk is present after teh case was set to slash.
         condition = comment; // If true, then switch condition to comment.
        } else if (c == '/') { // Detects if there is another slash after the condition was set to slash.
         condition = doubleSlash; 
        } else {
         printf("/%c", c); // Prints the character followed by a forward slash. The forward slash is used to indicate that something is a part of the output and not just the input.
         condition = normal;
        }
        break;
      
      case comment:
        if (c == '*') { // Detects if there is an asterisk. See 'case slash' code to understand
         condition = slashStar; // Switch condition to '/*' (slashStar).
        }
        break;
          
      case slashStar:
        if (c == '/') { // Detects if the current character is a '/'. 
         condition = normal; // This means the comment has ended.
        } else if {
         condition = comment; // This is a comment.
        }
        break;
      
      case doubleSlash:
        if (c == '\n') { // Detects if there is a new line.
        printf("\n"); // Print more new lines.
        condtion = normal;
       }
       break;
       }
   }
 }
  return 0;
} 
          
          
          
          
          
          
          
          
          
          
