#include "Simulation.h"

Simulation::Simulation() {
}

Simulation::~Simulation() {
  delete calculator;
  delete fileProcessor; //deleting the two instances of our classes
}

void Simulation::PrintInfo(){
  cout << "Would you like to start the game of life with a random configuration (0) or an input file (1): "; //asking the user how if they want to play through the console or through files
  cin >> userInput;

  if (userInput == 0) { //if they chose the random configuration, the below will execute
    cout << "Please input how many rows you desire: ";
    cin >> rows;
    cout << "Please input how many columns you desire: ";
    cin >> columns;
    cout << "Please input the population density you desire: ";
    cin >> popDense;
    calculator = new Calculator(rows, columns); //creating a calculator variable of size rows x columns
    calculator->DetermineStartingLocations(popDense); //creating the 2d array of chars given the popDense the user inputted

    cout << "Would you like the program to sleep between generations? (Y/N): ";
    cin >> sleepAnswer; //asking the user if they want a pause in between each generation

    if (sleepAnswer == 'N') {
      sleepTime = 0; //setting sleep time equal to 0 if they don't want a pause
    }
    else {
      cout << "How long would you like it to sleep in seconds?: ";
      cin >> sleepTime; //asking how many seconds the user want to pause for
    }

    cout << "Please enter what mode you would like to run (classic, mirror, doughnut): ";
    cin >> userResponse; //figuring out what mode the user wants to run in

    ConsoleModeDeterminer(); //method to determine how to execute each mode depending on the user's input
  }

  if (userInput == 1) { //if they want to play through files, this loop will execute
    cout << "Please enter the file input name: ";
    cin >> fileInput; //getting the file input name
    cout << "Please enter the file output name: ";
    cin >> fileOutput; //getting the file output name
    fileProcessor = new FileProcessor(); //creating an instance of the FileProcessor class
    rows = fileProcessor->GetRows(fileInput); //finding the number of rows through our FileProcessor method
    columns = fileProcessor->GetColumns(fileInput); //finding the number of columns through our FileProcessor method
    simArray = fileProcessor->GetArray(fileInput); //finding the 2d array of chars through our FileProcessor method
    calculator = new Calculator(rows, columns, simArray); //creating a calculator instance using the 2d array the user gave us
    calculator->OpenOut(fileOutput); //method to open the output file

    cout << "Please enter what mode you would like to run (classic, mirror, doughnut): ";
    cin >> userResponse;

    FileModeDeterminer();
    calculator->CloseOut(); //closing the output file
  }
}

void Simulation::ConsoleModeDeterminer() {
  if (userResponse == "classic") {
    calculator->PrintToConsole(); //printing the base generation first
    sleep(sleepTime); //pausing
    calculator->ClassicModeCalculator(); //running one loop of our classic mode
    calculator->PrintToConsole();
    sleep(sleepTime);
    calculator->ClassicModeCalculator(); //running again
    calculator->PrintToConsole();
    sleep(sleepTime);
    while (!calculator->isDone()){ //running until it stabilizes or oscillates
      calculator->ClassicModeCalculator();
      calculator->PrintToConsole();
      sleep(sleepTime);
    }
  }

  else if (userResponse == "mirror") {
    calculator->PrintToConsole(); //printing the base generation first
    sleep(sleepTime);
    calculator->MirrorModeCalculator(); //running one loop of our mirror mode
    calculator->PrintToConsole();
    sleep(sleepTime);
    calculator->MirrorModeCalculator(); //running again
    calculator->PrintToConsole();
    sleep(sleepTime);
    while (!calculator->isDone()){ //running until it stabilizes or oscillates
      calculator->MirrorModeCalculator();
      calculator->PrintToConsole();
      sleep(sleepTime);
    }
  }
  else if (userResponse == "doughnut") {
    calculator->PrintToConsole(); //printing the base generation first
    sleep(sleepTime);
    calculator->DoughnutModeCalculator(); //running one loop of our doughnut mode
    calculator->PrintToConsole();
    sleep(sleepTime);
    calculator->DoughnutModeCalculator(); //running again
    calculator->PrintToConsole();
    sleep(sleepTime);
    while (!calculator->isDone()){
      calculator->DoughnutModeCalculator(); //running until it stabilizes or oscillates
      calculator->PrintToConsole();
      sleep(sleepTime);
    }
  }
}

void Simulation::FileModeDeterminer() {
  if (userResponse == "classic") {
    calculator->PrintToFile(); //printing the base generation to a file first
    sleep(sleepTime);
    calculator->ClassicModeCalculator(); //running one loop of our classic mode
    calculator->PrintToFile();
    sleep(sleepTime);
    calculator->ClassicModeCalculator(); //running again
    calculator->PrintToFile();
    sleep(sleepTime);
    while (!calculator->isDone()){
      calculator->ClassicModeCalculator(); //running until it stabilizes or oscillates
      calculator->PrintToFile();
      sleep(sleepTime);
    }
  }
  else if (userResponse == "mirror") {
    calculator->PrintToFile(); //printing the base generation to a file first
    sleep(sleepTime);
    calculator->MirrorModeCalculator(); //running one loop of our mirror mode
    calculator->PrintToFile();
    sleep(sleepTime);
    calculator->MirrorModeCalculator(); //running again
    calculator->PrintToFile();
    sleep(sleepTime);
    while (!calculator->isDone()){
      calculator->MirrorModeCalculator(); //running until it stabilizes or oscillates
      calculator->PrintToFile();
      sleep(sleepTime);
    }
  }
  else if (userResponse == "doughnut") {
    calculator->PrintToFile(); //printing the base generation to a file first
    sleep(sleepTime);
    calculator->DoughnutModeCalculator(); //running one loop of our doughnut mode
    calculator->PrintToFile();
    sleep(sleepTime);
    calculator->DoughnutModeCalculator(); //running again
    calculator->PrintToFile();
    sleep(sleepTime);
    while (!calculator->isDone()){
      calculator->DoughnutModeCalculator(); //running until it stabilizes or oscillates
      calculator->PrintToFile();
      sleep(sleepTime);
    }
  }
}
