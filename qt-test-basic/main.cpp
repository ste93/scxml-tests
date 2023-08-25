#include <QCoreApplication>
#include <QScxmlStateMachine>
#include <QDebug>


#include <iostream>
#include "MyDataModel.h"
#include "MyStateMachine.h"

#include <thread>
#include <chrono>

void myFunction(MyStateMachine *machine)
{
  int count=10;
  while(--count) {
    std::cout<<"Thread is running...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    if (count%2==0)
      machine->submitEvent("start");
    else
      machine->submitEvent("stop");
  }

  QCoreApplication::quit();
}

int main(int argc, char *argv[])
{
  QCoreApplication app(argc, argv);
  MyDataModel dataModel;
  MyStateMachine stateMachine;
  stateMachine.setDataModel(&dataModel);

  stateMachine.start();

  std::thread t1(myFunction, &stateMachine);

  int ret=app.exec();

  t1.join();

  return ret;
  
}
