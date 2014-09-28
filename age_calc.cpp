// Asks the user for a birthdate, and calculates her current age
#include <QApplication>
#include "inputform.h"

int main(int argc, char** argv)
{
   QApplication ageApp{argc, argv};
   InputForm inputTest;
   return inputTest.exec();
}
