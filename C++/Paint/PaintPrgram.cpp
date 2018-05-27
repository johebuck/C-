/*
 * Author: John Buckley
 * Date: 9/19/2014
 * File: PainterProgram.cpp
 * Description: This program will ask the user for a row and a column and a character they would like to paint and will paint it to the appropriate destination
                and will continue to do so until the user has enter -1 for both row and column.
 */

#include <iostream> //STDIN, STDOUT

using namespace std;

const int MAX_HEIGHT = 10;
const int MAX_WIDTH = 20;

void initialize_picture(char picture[MAX_HEIGHT][MAX_WIDTH]);
/*
 * Description:
 *    Uses a nested for loop to initialize the picture to all spaces.
 *
 * Inputs:
 *   char picture [] [];
 *     A 2D array consisting of the rows and columns for the picture
 *
 * Output:
 *   first blank picture
 */


void print_picture(const char picture[MAX_HEIGHT][MAX_WIDTH]);
/*
 * Description:
 *   Uses a nested for loop to print the picture to the screen.
 *
 * Inputs:
 *   const char picture [MAX] [MAX]
 *     A 2D array consisting of the rows and columns for the picture
 *
 * Output:
 *   Will print the character the user typed in adding it to the picture
 */



void make_picture(char picture[MAX_HEIGHT][MAX_WIDTH]);
/*
 * Description:
 *   Uses a loop and allows the user to play the game. Should ask the user for the row, col, and pixel value, and exit cleanly when they are done playing.
 *
 * Inputs:
 *   char picture [MAX] [MAX]
 *     A 2D array consisting of the rows and columns for the picture
 *
 * Output
 *   Will ask the user for the row column and character
 */




void paint_pixel(char picture[MAX_HEIGHT][MAX_WIDTH], int row, int col, char pixel);
/*
 * Description:
 *  Changes the value of the picture at row, col to pixel (which is only one line). When you get everything else working, this is where you should do
 *  your error checking. If they enter incorrect row & col values you should print an error and leave the picture unchanged for that iteration.
 *
 * Inputs:
 *   char picture [MAX] [MAX], int row, int col, char pixel
 *     A 2D array consisting of the rows and columns for the picture. An integer for the desired row. An integer for the desired column. Character for desired pixel
 *
 * Output
 *   If they enter invalid inputs it will display a message saying it can't be used and to try again
 */




 void swap_all(char picture[MAX_HEIGHT][MAX_WIDTH], char source, char target);
/*
 * Description:
 *   Loops over the entire image, swapping all instances of the character "source" with the supplied character "target". The purpose of this method is
 *   so that the user can easily define a blanket substitution over all characters of a given type. For instance if source is "@" and target is "#"
 *   you should replace all occurrences of "@" in your image with "#"..
 *
 * Inputs:
 *   char picture, char source, char target
 *     A 2D array consisting of the rows and columns for the picture. A character for source that will be written over. A character for target which is what
 *     will replace the char source.
 *
 * Output
 *   Will swap all of the characters labeled as char source with the char labeled as char target.
 */
 void final_print(char picture[MAX_HEIGHT][MAX_WIDTH], int row, int col, char pixel);
/*
    Description:
        Prints the picture out one last final time

    Input:
        char picture[][], int row, int col, char pixel
         A 2D array consisting of the rows and columns for the picture. An integer for the row. An Integer for the column. A character for the pixel.

    Output:
        The final print

*/



 int main(){

    char picture[MAX_HEIGHT][MAX_WIDTH]; int row; int col; char pix; char source; char target;

    initialize_picture(picture);

    make_picture(picture);

 return 0;
}




//initializes the picture, sets all the spaces of the picture with blanks
 void initialize_picture(char picture[MAX_HEIGHT][MAX_WIDTH]){

    for(int i=0; i<MAX_HEIGHT; i++){

        for(int j=0; j<MAX_WIDTH; j++){

            picture[i][j]=' ';

        }
    }
}




//prints the picture which should be whatever you initialized it to, in this case blank spaces
 void print_picture(const char picture[MAX_HEIGHT][MAX_WIDTH]){

    for(int i=0; i<MAX_HEIGHT; i++){

        for(int j=0; j<MAX_WIDTH; j++){

            cout<<picture[i][j];
        }

        cout<<'\n';

    }
}





//outputs the welcoming statement, the dimensions of the canvas, and the message displaying the empty canvas.
//It then asks the user for the row and the column they want to place a character in and asks for that character.
//If the dimensions the user asked for are not within the bounds of the canvas, have it output a message and to try again.
 void make_picture(char picture[MAX_HEIGHT][MAX_WIDTH]){

    int row = 0; int col = 0; char pixel, source, target;

    cout << "Welcome to Do you even ASCII art bro?" << endl;

    cout << endl;

    cout << "This future work of art is only 20 pixels in length and 10 pixels in height, make them count." << endl;

    cout << endl;

    cout << "This is your empty canvas, please don't mess it up." << endl;

    cout << endl;

    print_picture(picture);

    cout << endl;

    do{
        cout << "Please enter the row: ";

        cin >> row;

        cout << "Please enter the column: ";

        cin >> col;

        cout << "Please enter the character that you would like to modify: ";

        cin >> pixel;

        cout << endl;

        if(-1==row||row>MAX_HEIGHT||-1==col||col>MAX_WIDTH){

            cout << "You can't paint on the walls, stick to the canvas. Try again." << endl;

            cout << endl;
        }

        else{

            picture[row][col] = pixel;

        }

        paint_pixel(picture, row, col, pixel);

        cout << endl;

        swap_all(picture, source, target);

    }

    while(row!=-1&&col!=-1);

    final_print(picture,row,col,pixel);

}




//This will take the character entered by the user and place it within the row and column specified by the user
 void paint_pixel(char picture[MAX_HEIGHT][MAX_WIDTH], int row, int col, char pixel){

    cout << "You're still no Van Gogh but it's getting there." << endl;

    for(int i = 0; i < MAX_HEIGHT; i++){

        for(int j = 0; j < MAX_WIDTH; j++){

            cout << picture[i][j];

        }

        cout << endl;

    }

    cout << endl;

}




//This asks the user if he would like to make a blanket change, if prompted yes it asks the user for the target location and
//the character they would like to change it too.
 void swap_all(char picture[MAX_HEIGHT][MAX_WIDTH], char source, char target){

    char option;

    cout << "Would you like to make a blanket change? If so, please enter 'Y', otherwise enter 'N'";

    cin >> option;

    cout << endl;

    while(option=='Y'){

        cout << "Please enter the target character: ";

        cin >> target;

        cout << "Now enter the character you would like to change the target character into: ";

        cin >> source;

        for(int i=0; i<MAX_HEIGHT; i++){

            for(int j=0; j<MAX_WIDTH; j++){

                while(picture[i][j]==target){

                    picture[i][j]=source;

                }

            }

        }

        option = 'N';

        print_picture(picture);

    }

}




//This displays the picture one last time for the user
void final_print(char picture[MAX_HEIGHT][MAX_WIDTH], int row, int col, char pixel){

    cout << "Ready to see if you've impressed me with your painting?" << endl;

    cout << endl;

    paint_pixel(picture, row, col, pixel);

    cout << "I'm not impressed, but thanks for trying" << endl;

}
