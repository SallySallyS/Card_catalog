// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H
#pragma onse

#include <QMainWindow>

// QT_BEGIN_NAMESPACE
// namespace Ui {
// class MainWindow;
// }
// QT_END_NAMESPACE

class QTableWidget;
class QSpinBox;
class QLineEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddClicked();

private slots:
    void onDeleteClicked();

private:
    QTableWidget* table;
    QLineEdit* nameInput;
    QLineEdit* secondNameInput;
    QLineEdit* middleNameInput;
    QSpinBox* ageInput;



// private:
//     Ui::MainWindow *ui;
};
// #endif // MAINWINDOW_H
