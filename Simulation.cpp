#include "Simulation.h"

Simulation::Simulation() {
}

Simulation::~Simulation() {
  delete calculator;
  delete fileProcessor;
}

void Simulation::PrintInfo(){
  cout << "Would you like to start the game of life with a random configuration (0) or an input file (1): ";
  cin >> userInput;

  if (userInput == 0) {
    cout << "Please input how many rows you desire: ";
    cin >> rows;
    cout << "Please input how many columns you desire: ";
    cin >> columns;
    cout << "Please input the population density you desire: ";
    cin >> popDense;
    calculator = new Calculator(rows, columns);
    calculator->DetermineStartingLocations(popDense);

    cout << "Would you like the program to sleep between generations? (Y/N): ";
    cin >> sleepAnswer;

    if (sleepAnswer == 'N') {
      sleepTime = 0;
    }
    else {
      cout << "How long would you like it to sleep in seconds?: ";
      cin >> sleepTime;
    }

    cout << "Please enter what mode you would like to run (classic, mirror, doughnut): ";
    cin >> userResponse;

    ConsoleModeDeterminer();
  }

  if (userInput == 1) {
    cout << "Please enter the file input name: ";
    cin >> fileInput;
    cout << "Please enter the file output name: ";
    cin >> fileOutput;
    fileProcessor = new FileProcessor();
    rows = fileProcessor->GetRows(fileInput);
    columns = fileProcessor->GetColumns(fileInput);
    simArray = fileProcessor->GetArray(fileInput);
    calculator = new Calculator(rows, columns, simArray);
    calculator->OpenOut(fileOutput);

    cout << "Please enter what mode you would like to run (classic, mirror, doughnut): ";
    cin >> userResponse;

    FileModeDeterminer();
    calculator->CloseOut();
  }
}

void Simulation::ConsoleModeDeterminer() {
  if (userResponse == "classic") {
    calculator->PrintToConsole();
    sleep(sleepTime);
    calculator->ClassicModeCalculator();
    calculator->PrintToConsole();
    sleep(sleepTime);
    calculator->ClassicModeCalculator();
    calculator->PrintToConsole();
    sleep(sleepTime);
    while (!calculator->isDone()){
      calculator->ClassicModeCalculator();
      calculator->PrintToConsole();
      sleep(sleepTime);
    }
  }

  else if (userResponse == "mirror") {
    calculator->PrintToConsole();
    sleep(sleepTime);
    calculator->MirrorModeCalculator();
    calculator->PrintToConsole();
    sleep(sleepTime);
    calculator->MirrorModeCalculator();
    calculator->PrintToConsole();
    sleep(sleepTime);
    while (!calculator->isDone()){
      calculator->MirrorModeCalculator();
      calculator->PrintToConsole();
      sleep(sleepTime);
    }
  }
  else if (userResponse == "doughnut") {
    calculator->PrintToConsole();
    sleep(sleepTime);
    calculator->DoughnutModeCalculator();
    calculator->PrintToConsole();
    sleep(sleepTime);
    calculator->DoughnutModeCalculator();
    calculator->PrintToConsole();
    sleep(sleepTime);
    while (!calculator->isDone()){
      calculator->DoughnutModeCalculator();
      calculator->PrintToConsole();
      sleep(sleepTime);
    }
  }
}

void Simulation::FileModeDeterminer() {
  if (userResponse == "classic") {
    calculator->PrintToFile();
    sleep(sleepTime);
    calculator->ClassicModeCalculator();
    calculator->PrintToFile();
    sleep(sleepTime);
    calculator->ClassicModeCalculator();
    calculator->PrintToFile();
    sleep(sleepTime);
    while (!calculator->isDone()){
      calculator->ClassicModeCalculator();
      calculator->PrintToFile();
      sleep(sleepTime);
    }
  }
  else if (userResponse == "mirror") {
    calculator->PrintToFile();
    sleep(sleepTime);
    calculator->MirrorModeCalculator();
    calculator->PrintToFile();
    sleep(sleepTime);
    calculator->MirrorModeCalculator();
    calculator->PrintToFile();
    sleep(sleepTime);
    while (!calculator->isDone()){
      calculator->MirrorModeCalculator();
      calculator->PrintToFile();
      sleep(sleepTime);
    }
  }
  else if (userResponse == "doughnut") {
    calculator->PrintToFile();
    sleep(sleepTime);
    calculator->DoughnutModeCalculator();
    calculator->PrintToFile();
    sleep(sleepTime);
    calculator->DoughnutModeCalculator();
    calculator->PrintToFile();
    sleep(sleepTime);
    while (!calculator->isDone()){
      calculator->DoughnutModeCalculator();
      calculator->PrintToFile();
      sleep(sleepTime);
    }
  }
}
