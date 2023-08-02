#include <QCoreApplication>
#include <QScxmlStateMachine>
#include <QDebug>

#include <iostream>

#include "MyStateMachine.h"

#include <thread>
#include <chrono>

void myFunction(MyStateMachine *machine)
{
  int count=0;
  while(true) {
    std::cout<<"Thread is running...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    if (count%2==0)
      machine->submitEvent("start");
    else
      machine->submitEvent("stop");
    
    count++;
  }
  
}

int main(int argc, char *argv[])
{
  QCoreApplication app(argc, argv);

  MyStateMachine stateMachine;

  stateMachine.start();

  std::thread t1(myFunction, &stateMachine);

  return app.exec();
  
}
