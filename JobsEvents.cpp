//позже нужно будет ввести систему прогрессии
//чтобы игрок не мог сразу устроиться высокооплачиваемую работу
//например, добавить очки опыта и давать их за приобритение имущества (когда оно будет в игре),
//и начиная с n-го кол-ва очков открывать новую работу

#include "mainwindow.h"

void MainWindow::jobsOption1()
{
    //Администратор группы в соцсети
    jobID = 1;
    jobStatus(jobID);
}

void MainWindow::jobsOption2()
{
    //Фрилансер-разнорабочий
    jobID = 2;
    jobStatus(jobID);
}

void MainWindow::jobsOption3()
{
    //Сборщик компьютеров в мастерской
    jobID = 3;
    jobStatus(jobID);
}

void MainWindow::jobsOption4()
{
    //Верстальщик сайтов
    jobID = 4;
    jobStatus(jobID);
}

void MainWindow::jobsOption5()
{
    //Помощник сисадмина
    jobID = 5;
    jobStatus(jobID);
}

void MainWindow::jobsOption6()
{
    //Разработчик в маленькой компании
    jobID = 6;
    jobStatus(jobID);
}
