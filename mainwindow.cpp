#include "mainwindow.h"
#include <QHBoxLayout>
#include <QTableWidget>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QStatusBar>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

    // , ui(new Ui::MainWindow)
{
    // ui->setupUi(this);

        QStatusBar *statusBar = new QStatusBar(this);
        setStatusBar(statusBar);
        statusBar->show();

        QWidget* centralWidget = new QWidget;
        setCentralWidget(centralWidget);
        QHBoxLayout* mainLayout = new QHBoxLayout;
        centralWidget->setLayout(mainLayout);

        table = new QTableWidget;
        table->setColumnCount(4);
        table->setHorizontalHeaderLabels(QStringList() <<"Name" << "Second Name" << "Middle name"<< "Age");
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        table->setSelectionMode(QAbstractItemView::SingleSelection);
        mainLayout->addWidget(table);

        QVBoxLayout* verticalLayout = new QVBoxLayout;
        mainLayout->addLayout(verticalLayout);

        verticalLayout -> addWidget(new QLabel("Name: "));
        nameInput = new QLineEdit;
        nameInput ->setToolTip("Enter your name");
        nameInput->setStatusTip("Please enter your full name");
        nameInput ->setWhatsThis("Enter your name here to move it to the left table.");
        verticalLayout -> addWidget(nameInput);


        verticalLayout -> addWidget(new QLabel("Second Name: "));
        secondNameInput = new QLineEdit;
        secondNameInput ->setToolTip("Enter your second name");
         secondNameInput->setStatusTip("Please enter your second name");
        secondNameInput ->setWhatsThis("Enter your second name here to move it to the left table.");
        verticalLayout -> addWidget(secondNameInput);


        verticalLayout -> addWidget(new QLabel("Middle name: "));
        middleNameInput = new QLineEdit;
        middleNameInput ->setToolTip("Enter your middle name");
         middleNameInput->setStatusTip("Please enter your middle name");
        middleNameInput ->setWhatsThis("Enter your middle name here to move it to the left table.");
        verticalLayout -> addWidget(middleNameInput);


        verticalLayout -> addWidget(new QLabel("Age: "));
        ageInput = new QSpinBox;
        ageInput->setMinimum(1);
        ageInput->setMaximum(130);
        ageInput ->setToolTip("Enter your age");
        ageInput->setStatusTip("Please enter your age (numeric value)");
        ageInput ->setWhatsThis("Enter your age here to move it to the left table.");
        verticalLayout -> addWidget(ageInput);

        QPushButton* addButton = new QPushButton("Add");
        addButton ->setToolTip("Add pashion to table");
         addButton->setStatusTip("Click to add the entered data to the table");
        addButton ->setWhatsThis("When clicked, this button will add data to the left table.");
        connect(addButton, &QPushButton::clicked, this, &MainWindow:: onAddClicked);
        verticalLayout -> addWidget(addButton);

        QPushButton* deleteButton = new QPushButton("Delete");
        deleteButton->setToolTip("Delete selected row");
        deleteButton->setStatusTip("Click to delete selected row from the table");
        deleteButton->setWhatsThis("When clicked, this button will remove the selected row from the table.");
        connect(deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteClicked);
        verticalLayout->addWidget(deleteButton);

        verticalLayout->addStretch();
}


MainWindow::~MainWindow()
{
//     delete ui;
}

void MainWindow::onAddClicked()
{
    const QString name = nameInput->text().trimmed();
    const QString secondName = secondNameInput->text().trimmed();
    const QString middleName = middleNameInput->text().trimmed();
    const int age = ageInput->value();


    if(name.isEmpty() || secondName.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Name and Second Name fields cannot be empty!");
        return;
    }

    if(age < 1 || age > 130) {
        QMessageBox::warning(this, "Warning", "Please enter a valid age (1-150)");
        return;
    }

    const int rowCount = table->rowCount();
    table->setRowCount(rowCount + 1);
    table->setItem(rowCount, 0, new QTableWidgetItem(name));
    table->setItem(rowCount, 1, new QTableWidgetItem(secondName));
    table->setItem(rowCount, 2, new QTableWidgetItem(middleName));
    table->setItem(rowCount, 3, new QTableWidgetItem(QString::number(age)));

    nameInput->clear();
    secondNameInput->clear();
    middleNameInput->clear();
    ageInput->setValue(1);
}


void MainWindow:: onDeleteClicked()
{
    QList<QTableWidgetItem*> selectedItems = table->selectedItems();
    if(selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a row to delete");
        return;
    }
    int rowToDelete = selectedItems.first()->row();
    table->removeRow(rowToDelete);
}
