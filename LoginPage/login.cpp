#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:/Users/Nick/Documents/Qt Project/LoginPage/Assets/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    if (!connOpen()) {
        ui->label->setText("failed to connect");
    } else {
        ui->label->setText("Connected");
    }
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_Password->text();

    if (!connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    QSqlQuery queries;
    queries.prepare("SELECT * FROM Student WHERE StudentID=:username AND Password=:password");
    queries.bindValue(":username", username);
    queries.bindValue(":password", password);

    if (!queries.exec()) {
        qDebug() << "Query execution failed: " << queries.lastError();
        return;
    }

    int count = 0;
    while (queries.next()) {
        count++;
    }

    if (count == 1) {
        ui->label_4->setText("Success");

    } else {
        ui->label_4->setText("Failed");
    }
}

void Login::on_pushButton_2_clicked()
{
    this->hide();
    IDRegister idregister;
    idregister.setModal(true);
    idregister.exec();

}
