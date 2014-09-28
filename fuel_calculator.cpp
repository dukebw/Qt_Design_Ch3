#include <QInputDialog>
#include <QMessageBox>
#include <QApplication>
#include <QTextStream>
#include <QString>

enum class FuelKind {
   litersPer100Km, milesPerGallon, unknown
};

class Fuel {
public:
   Fuel(const double& amt, FuelKind kind);
   Fuel ()
      :m_amount{0}, m_kind{FuelKind::unknown} {}

   FuelKind getKind() const { return m_kind; }
   double getAmount() const { return m_amount; } 
   QString string();
private:
   double m_amount{0};
   FuelKind m_kind{FuelKind::litersPer100Km};
};

Fuel::Fuel(const double& amt, FuelKind kind)
   :m_amount{amt}, m_kind{kind} {}

QString Fuel::string()
{
   QString fuelString;
   QTextStream fuelStream{&fuelString};
   switch(m_kind) {
      case FuelKind::milesPerGallon:
      {
         fuelStream << m_amount << " MPG";
         return fuelString;
      }
      case FuelKind::litersPer100Km:
      {
         fuelStream << m_amount << " L per 100 km";
         return fuelString;
      }
      default:
         return nullptr;
   }
}

Fuel convertFuel(const Fuel& fuelInput)
{
   static const double mpgToL100km{235.214583};
   switch(fuelInput.getKind()) {
      case FuelKind::litersPer100Km:
         return Fuel{fuelInput.getAmount() / mpgToL100km, FuelKind::milesPerGallon};
      case FuelKind::milesPerGallon:
         return Fuel{fuelInput.getAmount() * mpgToL100km, FuelKind::litersPer100Km};
      default:
         return Fuel{0, FuelKind::unknown};
   }
}

int main(int argc, char** argv)
{
   QApplication fuelApp{argc, argv};
   double amount = QInputDialog::getDouble(nullptr, "Fuel Conversion", 
         "Please enter an amount: ", 0, 0);
   QStringList items;
   QString mpgString{"Miles per gallon"};
   QString lp100KmString{"Liters per 100 km"};
   items << mpgString << lp100KmString;

   bool ok;
   QString item = QInputDialog::getItem(nullptr, "Fuel Conversion", 
         "Enter fuel type: ", items, 0, false, &ok);

   if (ok) {
      Fuel convertedFuel;
      if (item == mpgString) {
         convertedFuel = convertFuel(Fuel{amount, FuelKind::milesPerGallon});
         QString convFuelString{convertedFuel.string()};
         QMessageBox::information(nullptr, lp100KmString, convFuelString);
      }
      else if (item == lp100KmString) {
         convertedFuel = convertFuel(Fuel{amount, FuelKind::litersPer100Km});
         QString convFuelString{convertedFuel.string()};
         QMessageBox::information(nullptr, mpgString, convFuelString);
      }
   }
}
