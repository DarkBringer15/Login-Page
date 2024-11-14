#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "idregister.h"
namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase mydb;
    bool connOpen() {

        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/Nick/Documents/Qt Project/LoginPage/Database/mydb.db");
        if (!mydb.open()) {
            qDebug ()<< ("failed to connect");
            return false;
        } else {
            qDebug() << ("Connected");
            return true;
        }
    }
    void connClose() {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;

};

#endif // LOGIN_H
