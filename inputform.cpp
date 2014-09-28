#include "inputform.h"
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QMessageBox>
#include <QDialog>
#include <QString>
#include <QDate>
#include <QDateEdit>

InputForm::InputForm(QWidget* parent)
   :QDialog{parent}
{
   setWindowTitle("QFormlayout demo");
   m_birthday = new QDateEdit;
   m_birthday->setDisplayFormat("dd/MM/yyyy");
   
   m_buttons = new QDialogButtonBox{QDialogButtonBox::Ok | QDialogButtonBox::Cancel};

   QVBoxLayout* vbox{new QVBoxLayout};
   QFormLayout* layout{new QFormLayout};

   layout->addRow(tr("Birthdate"), m_birthday);

   vbox->addLayout(layout);
   vbox->addWidget(m_buttons);

   Q_ASSERT(vbox->parent() == nullptr);
   Q_ASSERT(m_birthday->parent() == nullptr);
   setLayout(vbox);

   Q_ASSERT(vbox->parent() == this);
   Q_ASSERT(m_birthday->parent() == this);

   connect(m_buttons, SIGNAL(accepted()), this, SLOT(accept()));
   connect(m_buttons, SIGNAL(rejected()), this, SLOT(reject()));
}

void InputForm::accept()
{
   QDate birthday{m_birthday->date()};
   int days{birthday.daysTo(QDate::currentDate())};
   QMessageBox::information(this, tr("Age Guesser"), tr("You are %1 years old.")
         .arg(days / 365));
   QDialog::accept();
}
