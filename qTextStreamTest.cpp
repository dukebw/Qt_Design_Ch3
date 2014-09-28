// Test of reading to and from files with QTextStream
#include <QTextStream>
#include <QString>

int main()
{
   QTextStream cout{stdout};
   QString s;
   QTextStream out{&s};
   out.setFieldWidth(10);
   out.setFieldAlignment(QTextStream::AlignCenter);
   out.setPadChar('-');
   out << "Qt" << "rocks!";
   cout << s << endl;
}
