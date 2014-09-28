#ifndef INPUTFORM_H
#define INPUTFORM_H

#include <QDialog>
class QDateEdit;
class QPushButton;
class QDialogButtonBox;

class InputForm : public QDialog {
   Q_OBJECT
public:
   explicit InputForm(QWidget* parent = 0);
protected slots:
   void accept();
private:
   QDateEdit* m_birthday;
   QDialogButtonBox* m_buttons;
};

#endif // INPUTFORM_H
