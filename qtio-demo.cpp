#include <QDate>
#include <QTextStream>
#include <QInputDialog>
#include <QApplication>
#include <iostream>

QTextStream cout(stdout, QIODevice::WriteOnly);
QTextStream cin(stdin, QIODevice::ReadOnly);
QTextStream cerr(stderr, QIODevice::WriteOnly);

bool yes(QString question)
{
   QString ans;
   cout << QString(" %1 [y/n]? ").arg(question);
   cout.flush();
   ans = cin.readLine();
   return (ans.startsWith("Y", Qt::CaseInsensitive));
}

int main(int argc, char** argv)
{
   QApplication dateApp{argc, argv};
   QDate d1{2002, 4,1}, d2{QDate::currentDate()};
   int days;
   cout << "The first date is: " << d1.toString()
      << "\nToday's date is " << d2.toString("ddd MMMM d, yyyy") << endl;

   if (d1 < d2)
      cout << d1.toString("MM/dd/yy") << " is earlier than "
         << d2.toString("yyyyMMdd") << endl;

   cout << "There are " << d1.daysTo(d2) << " days between "
      << d1.toString("MMM dd, yyyy") << " and " << d2.toString(Qt::ISODate) << endl;

   days = QInputDialog::getInt(nullptr, "Add Days", "Enter number of days to add to "
         "the first date: ", 0, 0);
   cout << "The first date was " << d1.toString() << "\nThe computer date is "
      << d1.addDays(days).toString() << endl;
   cout << "First date displayed in longer format: "
      << d1.toString("dddd, MMMM dd, yyyy") << endl;
   return 0;
}
