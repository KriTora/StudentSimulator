#include "mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow::EducOption1()  // сходить на пару
{
    mental_condition-=10;
    chance+=7;
}
void MainWindow::EducOption2()  //послушать лекцию
{
    mental_condition-=15;
    chance+=10;
}
void MainWindow::EducOption3()  //сделать д/з
{
    mental_condition-=10;
    chance+=7;
}
void MainWindow::EducOption4() //купить книги
{
    if (money >= 100)  chance += 5;
    else
    {
        Education_notEnoughMoney->setText("Недостаточно денег! Нужно ещё " + QString::number(100 - money) + " р.");
        Education_notEnoughMoney->show();
    }
}
void MainWindow::EducOption5() //купить курсы
{
    if (money >= 1500)  chance += 20;
    else
    {
        Education_notEnoughMoney->setText("Недостаточно денег! Нужно ещё " + QString::number(1500 - money) + " р.");
        Education_notEnoughMoney->show();
    }

}
void MainWindow::EducOption6() //нанять репетитора
{
    if (money >= 2500)  chance += 33;
    else
    {
        Education_notEnoughMoney->setText("Недостаточно денег! Нужно ещё " + QString::number(2500 - money) + " р.");
        Education_notEnoughMoney->show();
    }
}
void MainWindow::EducOption7() //попробовать сдать сессию
{
    int temp= rand()%101;
    if (temp<=chance)
    {
        check=true;
    } else check =false;
    if (check)
    {
        xp+=100;
        mental_condition+=20;
        chance=0;
        ui->button_session->setEnabled(false);
        ui->button_session2->setEnabled(false);
    } else
    {
        mental_condition -=30;
        HP-=30;
        ExamFail->setText("У вас не получилось сдать сессию, готовьтесь лучше");
    }

}
void MainWindow::EducOption8() //купить сессию
{
if (money>=50000)
{
    xp+=50;
    chance=0;
    ui->button_session->setEnabled(false);
    ui->button_session2->setEnabled(false);

}
else Education_notEnoughMoney->setText("Недостаточно денег! Нужно еще " + QString::number(50000-money) + " р.");
}
void MainWindow::EducOption9() //защитить курсовую
{
    int temp= rand()%101;
    if (temp<=chance)
    {
        check=true;
    } else check =false;
    if (check)
    {
        xp+=150;
        mental_condition+=30;
        chance=0;
        ui->button_courseWork->setEnabled(false);
        ui->button_courseWork2->setEnabled(false);

    } else
    {
        mental_condition -=30;
        HP-=30;
        ExamFail->setText("У вас не получилось защитить курсовую, готовьтесь лучше");
    }

}
void MainWindow::EducOption10() //купить курсовую
{
    if (money>=100000)
    {
        xp+=50;
        chance=0;
        ui->button_courseWork->setEnabled(false);
        ui->button_courseWork2->setEnabled(false);
    }
    else Education_notEnoughMoney->setText("Недостаточно денег! Нужно еще " + QString::number(100000-money) + " р.");
}
void MainWindow::EducOption11() //защитить диплом
{
    int temp= rand()%101;
    if (temp<=chance)
    {
        check=true;
    } else check =false;
    if (check)
    {
        //тут должен быть метот конца игры,который ты сделаешь)

    } else
    {
        mental_condition -=30;
        HP-=30;
        ExamFail->setText("У вас не получилось защитить диплом, готовьтесь лучше");
    }
}
void MainWindow::EducOption12() //купить диплом
{
    if (money>=150000)
    {
         //тут должен быть метот конца игры,который ты сделаешь)
    }
    else Education_notEnoughMoney->setText("Недостаточно денег! Нужно еще " + QString::number(150000-money) + " р.");
}
