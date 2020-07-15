/*
Creator: Aniebiet Jacob
Date: 2/10/2019
Description: This code is a simulator for manhunt and will allow the user/'investigator' to search for a given target on the map.
*/

#include <iostream>
#include <fstream>
using namespace std;



const int BOARD_X = 10; //columns of board
const int BOARD_Y = 10; //rows of board
const int POS_X = 1; //the x coordinate
const int POS_Y = 2; //the y coodinate
const char TARGET = 'T'; //The symbol used for the Target
const char INVEST = 'I'; // The symbol used for the Investigator
const char PATH = '*'; //The symbol used to mark the investigator's path
const char SPACE = '_'; //The symbol used to indicate a free board space



/*
  startMenu()
  pre - none
  post -  will return the user's selection as an integer of either load simulation, start a new simulation, or exit
*/
int startMenu();


/*
  mainMenu()
  pre - none
  post - will return the user's selection as an integer of either which direction to move, to see map or to eit the simulation
*/
int mainMenu();


/*
 createBoard()
 pre - pass in the 2D char array map
 post - initialize each space and prints the map
*/
int createBoard(char map1[BOARD_X][BOARD_Y]);


/*
  createBoard()
  pre - there exists a 2D array map with spaces already stored in it
  post - each space in board will be printed out with the investigators new position and the path they've already followed
*/
int createBoard(char map1[BOARD_X][BOARD_Y], int coorI[2], char INVEST);


/*
  newMap()
  pre - the array for the coordinates of the target and investigator have been formed
  post - the arrays with the coordinates of the target and invesigator will be updated with the user's choices.
*/
int newMap(int coorI[2], int coorT[2]);


/*
  makeMove()
  pre - there exists a 2D char array map, there are coordinates for both the target and investigator, there is a createBoard() function and a checkSearch() function and a mainMenu() function already defined
  post - The invegator's position will be moved throughout the 2D array map1 until it reaches the coordinates of the target.
*/
int makeMove(int coorI[2], int coorT[2], char map1[BOARD_X][BOARD_Y]);


/*
  checkSearch()
  pre- the array for the coordinates of the target and investigator have been formed
  post- Will tell user whether to go either east or west then either north or south
*/
int checkSearch( int coorI[2], int coorT[2]);


/*
  loadFile()
  pre - arrays for coordinates of both the target and invesgator will be made.
  post - the saved coordinates from the text file will be extracted and put into the array coordinates for the target and the investigator.
*/
int loadFile( int coorI[2], int coorT[2]);


/****************************************************************************/



int main(){

  //Item required for first swtich statment in main from startMenu()
  int selection = 0;

  //Arrays used for the coard and coordinates of the investigator and target
  char map1[BOARD_X][BOARD_Y];
  int coorI[2];
  int coorT[2];


  //Initializes the creation of the board with the function createBoard
  cout << endl;
  createBoard(map1);

  cout<< "WELCOME TO MANHUNT"<< endl;


  //inititalizes the return from startMenu() to variable selection
  selection = startMenu();


  //Based on selection's value, chooses one of three options from the Menu
  switch (selection)
    {

    case 1:

      //Loads a file the user has already saved
      loadFile( coorI, coorT);
      break;

    case 2:

      //Creates a new MANHUNT simulation
      newMap(coorI, coorT);
      break;

    case 3:

      //Cuts of program if case 3 is selected
      cout << "Leaving so soon?" << endl
	   << "Okay, goodbye!" << endl;
      return 0;
      break;

    default:

      //Prints an error message and then puts out the menu again
      cout << "ERROR, Please select a number 1-3" << endl;
      startMenu();
    }

  makeMove(coorI, coorT, map1);
  return 0;

}


/*
  makeMove()
  Given the coordinates of the investigator and the target and given the board, creates an updated version of the board with the invesigator's position and the path they have taken until the user exits or the target is found.
*/
int makeMove(int coorI[2], int coorT[2], char map1[BOARD_X][BOARD_Y]){

  int selection = 0;

  //Continues to loop through simulation if the invesigator's coordinates don't match the target's coordinates.
  while(coorI[POS_X] != coorT[POS_X] or coorI[POS_Y] != coorT[POS_Y]){
    createBoard(map1, coorI, INVEST);
    selection = mainMenu();



    //Based on selection value, will move the invesigator on the board, show the board or exit the simulation.
    switch (selection)
      {

      case 1:


	//If north doesn't move the invesigator off the range of the board, moves the investigator north.
	if((coorI[POS_Y] - 1) > -1 and (coorI[POS_Y] - 1) < BOARD_Y){
	  map1[coorI[POS_Y]][coorI[POS_X]] = PATH;
	  coorI[POS_Y] = coorI[POS_Y] - 1;
	}


	//If north will move the invesigator off the range of the board, prints error message.
	else
	  cout << endl << "STOP! You can't move North or you will move off the board!";
	break;


      case 2:

	//If east doesn't move the invesigator off the range of the board, moves the investigator east.
	if((coorI[POS_X] + 1) > -1 and (coorI[POS_X] + 1) < BOARD_X){
	  map1[coorI[POS_Y]][coorI[POS_X]] = PATH;
	  coorI[POS_X] = coorI[POS_X] + 1;
	}


	//If east will move the invesigator off the range of the board, prints error message.
	else
          cout << endl << "STOP! You can't move East or you will move off the board!";
        break;


      case 3:

	//If south doesn't move the invesigator off the range of the board, moves the investigator south.
	if((coorI[POS_Y] + 1) > -1 and (coorI[POS_Y] + 1) < BOARD_Y){
	  map1[coorI[POS_Y]][coorI[POS_X]] = PATH;
	  coorI[POS_Y] = coorI[POS_Y] + 1;
	}


	//If south will move the invesigator off the range of the board, prints error message.
	else
          cout << endl << "STOP! You can't move South or you will move off the board!";
        break;



      case 4:

	//If west doesn't move the invesigator off the range of the board, moves the investigator west.
	if((coorI[POS_X] - 1) > -1 and (coorI[POS_X] - 1) < BOARD_X){
	  map1[coorI[POS_Y]][coorI[POS_X]] = PATH;
	  coorI[POS_X] = coorI[POS_X] - 1;
	}


	//If west will move the invesigator off the range of the board, prints error message.
	else
          cout << endl << "STOP! You can't move West or you will move off the board!";
        break;


      case 5:

	//Re-prints out board for user
        createBoard(map1, coorI, INVEST);
	cout << endl;
        break;


      case 6:

	//Kills the program for user
        cout << "Leaving so soon?" << endl
	     << "Okay, goodbye!" << endl;
	return 0;
        break;

      default:
	mainMenu();
      }


    //Utilizes the recommendation function to print recommendations for next move
    checkSearch(coorI, coorT);
    cout << endl;

  }


  //If user finds target, congradulates them, reveals the location of the target, and tells where the target was located.
  cout << "CONGRATULATIONS!" << endl;
  createBoard(map1, coorI, TARGET);
  cout << "Look at the Map! The target has been revealed! " << endl
       << "You found Target '" << TARGET << "' at coordinate ("
       << coorT[POS_X] << ", " << coorT[POS_Y] << ")!" << endl;

  return 0;

}

/*
  checkSearch()
  Given the coordinates of the investigator and the target, guides the user on which direction to move on the map
*/
int checkSearch(int coorI[2], int coorT[2]){



  //Goes through statment if the target and investigator aren't on the same X plane
  if (coorI[POS_X] != coorT[POS_X]){


    //Finds the difference between the x postions of the investigator and target, and if it is positive tells the user to go east
    if ((coorT[POS_X] - coorI[POS_X]) > 0){
      cout << endl << "Try Searching East";
    }


    //Finds the difference between the x postions of the investigator and target, and if it is negative tells the user to go west
    if ((coorT[POS_X] - coorI[POS_X]) < 0 ){
      cout << endl << "Try Searching West";
    }
  }


  //Goes through statment if the target and investigator are on the same X plane but not on the same Y plane
  else if (coorI[POS_Y] != coorT[POS_Y]){


    //Finds the difference between the y postions of the investigator and target, and if it is postive tells the user to go south
    if ((coorT[POS_Y] - coorI[POS_Y]) > 0){
      cout << endl << "Try Searching South";
    }


    //Finds the difference between the y postions of the investigator and target, and if it is negative tells the user to go north
    if ((coorT[POS_Y] - coorI[POS_Y]) < 0){
      cout << endl << "Try Searching North";
      }
  }
    return 0;
}





/*
  createBoard()
  Given the board, intitializes the spaces in the board.
*/
int createBoard(char map1[BOARD_X][BOARD_Y]){


  //Loops through every row in the array
  for(int i = 0; i < BOARD_Y; i++){


    //Loops through every space in each row in the array
    for(int j = 0; j < BOARD_X; j++){


      //Puts a space in that part of the array
      map1[i][j] = SPACE;
    }
  }

  return 0;
}


/*
  createBoard()
  Given the board and given coordinates of the target and the investigator, prints out the updated board with the position of the invesigator
*/
int createBoard(char map1[BOARD_X][BOARD_Y], int coorI[2], char INVEST){


  //Puts investigator in board in its current position
  map1[coorI[POS_Y]][coorI[POS_X]] = INVEST;


  //Loops through every row in the array
  for(int i = 0; i < BOARD_Y; i++){


    //Loops through every space in every row in the array
    for(int j = 0; j < BOARD_X; j++){


      //Prints out each space in the row with a space in between
      cout << map1[i][j] << " ";
    }

    //Ends row, moves to the next row
    cout << endl;
  }
  return 0;
}



/*
  startMenu()
  Asks user for a selection which is an integer 1-3 and returns the user's selection
*/
int startMenu(){

  int selection = 0;


  //Gives user options of selections for the menu and accepts an integer selection from the user
  cout << "What would you like to do?" << endl
       << "1. Load simulation from file" << endl
       << "2. Start a new simulation" << endl
       << "3. Leave" << endl
       << "Select a number 1-3" << endl;
  cin >> selection;



  //Reprompts user for new response if the primary response was an integer other than 1, 2 or 3
  while (selection!=3 and selection!=2 and selection!=1){
    cout << "Invalid selection! Please try again:" << endl
	 << "What would you like to do?" << endl
	 << "1. Load simulation from file" << endl
	 << "2. Start a new simulation" << endl
	 << "3. Leave" << endl
	 << "Select a number 1-3" << endl;
    cin >> selection;
  }

  return selection;
}


/*
  mainMenu()
  Ask the user for a selection which is an integer 1-6 and returns that selection
*/
int mainMenu(){

  int selection = 0;


  //Gives user options of selections for the menu and accepts an integer selection from the user
  cout << "What would you like to do?" << endl
       << "1. Search North" << endl
       << "2. Search East" << endl
       << "3. Search South" << endl
       << "4. Search West" << endl
       << "5. See Map" << endl
       << "6. Exit" << endl;
  cin >> selection;


  //Reprompts user for new response if the primary response was an integer other than 1, 2, 3, 4, 5 or 6
  while (selection != 6 and selection != 5 and selection != 4
	 and selection != 3 and selection != 2 and selection != 1)
  {
    cout << "Invalid selection! Retry: "<< endl
	 << "1. Search North" << endl
	 << "2. Search East" << endl
	 << "3. Search South" << endl
	 << "4. Search West" << endl
	 << "5. See Map" << endl
	 << "6. Exit" << endl;
    cin >> selection;
  }

  return selection;
}




/*
  newMap()
  Given the empty arrays for the target and the invesigator, initializes both coordinates
*/
int newMap(int coorI[2], int coorT[2]){




  //Request for X coordinate of investigator with a number from 0 to a number one less than the number of columns in the board
  cout << "What is the X axis of the invesitgator? "
       << "Please enter a number 0-"<< BOARD_X - 1 << endl;
  cin >> coorI[POS_X];


  //Repromts the user when the coordinate given is outside X's parameters of the board
  while (coorI[POS_X]> BOARD_X - 1 or coorI[POS_X] < 0 ){
    cout << "Invalid entry! Please enter a number 0-" << BOARD_X - 1 << endl;
    cin >> coorI[POS_X];
  }



  //Request for Y coordinate of investigator with a number from 0 to a number one less than the number of columns in the board
  cout << "What is the Y axis of the invesitgator? "
       << "Please enter a number 0-" << BOARD_Y - 1 << endl;
  cin >> coorI[POS_Y];


  //Repromts the user when the coordinate given is outside Y's parameters of the board
  while (coorI[POS_Y] > BOARD_Y - 1 or coorI[POS_Y] < 0){
    cout << "Invalid entry! Please enter a number 0-" << BOARD_Y - 1 << endl;
    cin >> coorI[POS_Y];
      }



  //Request for X coordinate of target with a number from 0 to a number one less than the number of columns in the board
  cout << "What is the X axis of the target? "
       << "Please enter a number 0-" << BOARD_X - 1 << endl;
  cin >> coorT[POS_X];


  //Repromts the user when the coordinate given is outside X's parameters of the board
  while (coorT[POS_X] > BOARD_X - 1 or coorT[POS_X] < 0){
    cout << "Invalid entry! Please enter a number 0-" << BOARD_X - 1 << endl;
    cin >> coorT[POS_X];
      }



  //Request for Y coordinate of target with a number from 0 to a number one less than the number of columns in the board
  cout << "What is the Y axis of the target? "
       << "Please enter a number 0-" << BOARD_Y - 1 << endl;
  cin >> coorT[POS_Y];


  //Repromts the user when the coordinate given is outside Y's parameters of the board
  while (coorT[POS_Y] > BOARD_Y - 1 or coorT[POS_Y] < 0){
    cout << "Invalid entry! Please enter a number 0-"<< BOARD_Y - 1 << endl;
    cin >> coorT[POS_Y];
      }

  return 0;
}


/*
  loadFile()
  Given the empty arrays for the target and the invesigator, reads in a text file and initializes both coordinates
*/
 int loadFile(int coorI[2], int coorT[2]){


   //Initialzes the c-string for the file and gets the file name from the user
  char theFile[100];
  cout << "What is the name of the file?:" << endl;
  cin >> theFile;


  //Opens the users given file for reading
  ifstream myFile;
  myFile.open(theFile, ios_base::in);


  //Reads in each line of the file, the X and Y coordinated of the investigator first and then the X and Y coordinates of the target
  myFile >> coorI[POS_X]
	 >> coorI[POS_Y]
	 >> coorT[POS_X]
	 >> coorT[POS_Y];

  return 0;

}
