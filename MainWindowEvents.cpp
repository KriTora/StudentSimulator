//для обработки событий
//про индексы стопки виджетов: индексация начинается с нуля, новый индекс назначается командой ui-><имя>->setCurrentIndex(int)
//(x)(название в дизайнере)
//(0)(TitleScreen) - главное меню
//(1)(StatsScreen) - характеристики героя
//(2)(JobsScreen) - работа
//(3)(ShopScreen) - магазин еды
//(4)(LeisureScreen) - магазин еды

#include "mainwindow.cpp"
#include "saves.h"

void MainWindow::quit()
{
    QApplication::quit();
}

void MainWindow::startGame()
{
    //в случае смерти героя игра устанавливает флажок game_over, который сигнализирует игре сбросить все игровые данные
    Start_Game->show();
    if(game_over == true)
    {
        money = 0,
        day = 1, month = 9, year = 2021,
        satiety = 100.f, hunger = 0.5f,
        mental_condition = 100.f, tireness = 0.5f,HP=100.f,damage=0.0f,
        jobID = 0,
        xp = 0;
        chance=0;
        jobStatus(jobID);

        game_over = false;
    }
    timer                               = new QTimer();
    QObject::connect(timer, &QTimer::timeout, this, &MainWindow::onTick);

    ui->stack->                         setCurrentIndex(1);
    setWindowTitle                      ("Ваши характеристики");
    timer->                             start(1000); //1000 мс = 1 с, т.е. меньше = быстрее течение времени в игре
    ui->frame_game_buttons->            show(); //вызов панели игровых кнопок
    ui->label_money->                   setText ("Деньги: " + QString::number(money) + " р.");
    ui->label_date->                    setText ("Дата: " + QString::number(day) + "." + QString::number(month) + "." + QString::number(year)); //вывод для первой секунды, иначе дата начнёт отображаться только от второго января
    ui->progressBar_hunger->            setValue(satiety);                                                                                      //а здесь выводы для того, чтобы полоски изначально не были пустыми
    ui->progressBar_mental_condition->  setValue(mental_condition);
    ui->progressBar_health->            setValue(HP);
    ui->progressBar_chance->            setValue(chance);

}

void MainWindow::onTick()
{
    //проверка срока обучения
    if (year == 2026 && month == 7 && day == 1) defeat();

    //обновление даты
    ++day;
    process(&day, &month, &year);

    //обновление сытости
    satiety -= hunger;
    ui->progressBar_hunger->setValue(satiety);
    HP-=damage; // если здоровье должно увеличиться, то можно damage присвоить отрицательное значение
    ui -> progressBar_health -> setValue(HP);
    mental_condition -= tireness;
    ui->progressBar_mental_condition->setValue(mental_condition);
    ui->progressBar_chance->setValue(chance);
    //за условие гибели беру меньше тысячной, потому что ещё не знаю, насколько сильно имущество будет сокращать расходы, иначе герой может умереть немного раньше, чем нужно
    if(satiety < 0.001)
    {
        timer->         stop();
        hunger_death->  show();
        hunger_death->  exec();
        game_over = true;
        emit(backToTitle());
    }

    if(mental_condition < 0.001)
    {
        timer->                     stop();
        mental_condition_death->    show();
        mental_condition_death->    exec();
        game_over = true;
        emit(backToTitle());
    }
    if(HP < 0.001)
    {
        timer->                     stop();
        HP_death->    show();
        HP_death->    exec();
        game_over = true;
        emit(backToTitle());
    }
    if (chance >=100)
    {
        chance=100;
    }

    //Разблокировка опций работы
    if (xp>=20) // если ты достиг 20 опыта, то открывается вторая работа,.так же надо сделать с остальными
    {
        ui->button_jobs_option2->setEnabled(true);
    }
    if (xp>=200)
    {
        ui->button_jobs_option3->setEnabled(true);
    }
    if (xp>=740)
    {
        ui->button_jobs_option4->setEnabled(true);
    }
    if (xp>=1100)
    {
        ui->button_jobs_option5->setEnabled(true);
    }
    if (xp>=1700)
    {
        ui->button_jobs_option6->setEnabled(true);
    }

    //Разблокировка опций сессии
    if (((day==1)&&(month==1))||((day==1)&&(month==6)))
    {
        ui->button_session->setEnabled(true);
        ui->button_session2->setEnabled(true);
    }
    if ((day==1)&&(month==1)&&((year==2023)||(year==2024)))
    {
        ui->button_courseWork->setEnabled(true);
        ui->button_courseWork->setEnabled(true);
    }
    if ((day==1)&&(month==1)&&(year==2026))
    {
        ui->button_GraduateWork->setEnabled(true);
        ui->button_GraduateWork2->setEnabled(true);
    }
    if (satiety > 100.0f)           satiety             = 100.0f; //ограничители для характеристик героя
    if (mental_condition > 100.0f)  mental_condition    = 100.0f; //чтоб бессмертным не был
    if (HP > 100.0f) HP=100.0f;

    //зарплата каждое первое число
    if(day == 1)
    {
        switch(jobID)
        {
        case 0:
            break;
        case 1:
            money += 3500;
            xp += 5;
            break;
        case 2:
            money += 5000;
            xp += 7;
            break;
        case 3:
            money += 8200;
            xp += 10;
            break;
        case 4:
            money += 12000;
            xp += 15;
            break;
        case 5:
            money += 15000;
            xp += 21;
            break;
        case 6:
            money += 24999;
            xp += 30;
            break;
        }
    }
    if ((day == 1)&&(month==7)&&(year==2025))
    {

}
    //обновление всех выводов
    ui->label_date->                    setText     ("Дата: " + QString::number(day) + "." + QString::number(month) + "." + QString::number(year));
    ui->progressBar_hunger->            setFormat   ("Сытость: " + QString::number(satiety) + ", затрата на день: " + QString::number(hunger));
    ui->progressBar_mental_condition->  setFormat   ("Настроение: " + QString::number(mental_condition) + ", затрата на день: " + QString::number(tireness));
    ui->label_money->                   setText     ("Деньги: " + QString::number(money) + " р.");
    ui->progressBar_health->            setFormat   ("Здоровье" + QString::number(HP)+ ", потери в день: " + QString::number(damage));
    ui->label_xp->                      setText     ("Опыт: " + QString::number(xp));
    ui->progressBar_chance->            setFormat   ("Шанс: " + QString::number(chance));

}

void MainWindow::backToTitle()
{
    ui->stack->setCurrentIndex(0);
    setWindowTitle("Главное меню");
    ui->frame_game_buttons->hide();
    timer->stop();
}

void MainWindow::toStats()
{
    ui->stack->setCurrentIndex(1);
}

void MainWindow::toJobs()
{
    ui->stack->setCurrentIndex(2);
    setWindowTitle("Работа");
}

void MainWindow::toShop()
{
    ui->stack->setCurrentIndex(3);
    setWindowTitle("Магазин");
}

void MainWindow::toLeisure()
{
    ui->stack->setCurrentIndex(4);
    setWindowTitle("Досуг");
}
void MainWindow::toEduc()
{
    ui->stack->setCurrentIndex(5);
    setWindowTitle("Магазин");
}
void MainWindow::jobStatus(int id)
{
    switch(id)
    {
    case 0:
        ui->label_job->setText("Работа: безработный [0 р./мес.]");
        break;
    case 1:
        ui->label_job->setText("Работа: администратор группы в соцсети [3500 р./мес.]");
        break;
    case 2:
        ui->label_job->setText("Работа: фрилансер-разнорабочий [5000 р./мес.]");
        break;
    case 3:
        ui->label_job->setText("Работа: сборщик компьютеров в мастерской [8200 р./мес.]");
        break;
    case 4:
        ui->label_job->setText("Работа: верстальщик сайтов [12000 р./мес.]");
        break;
    case 5:
        ui->label_job->setText("Работа: помощник сисадмина [15000 р./мес.]");
        break;
    case 6:
        ui->label_job->setText("Работа: разработчик в маленькой компании [24999 р./мес.]");
        break;
    }
}

bool MainWindow::Save()
{
    save save;  // я создал структуру, потому что мне нужны только эти поля, а если, создавать объект класса, то записивается слишком много лишнего
                // т.к мы в 1 класс засунули вообще все :D
    save.money              = money;
    save.day                = day;
    save.month              = month;
    save.year               = year;
    save.satiety            = satiety;
    save.hunger             = hunger;
    save.mental_condition   = mental_condition;
    save.HP                 = HP;
    save.damage             = damage;
    save.jobID              = jobID;
    save.tireness           = tireness;
    save.xp                 = xp;
    save.chance             = chance;

    std::ofstream fout;
    fout.open("save.dat", std::ios::binary | std::ios::out);
    if (!fout.is_open())
    {
        QMessageBox::critical(this, "Ошибка", "Не удалось создать файл загрузки");
        return false;
    }
    else
    {
    fout.clear();
    fout.write((char*)&save, sizeof(save));
    }

    fout.close();

    QMessageBox::information(this, "Успех", "Создано новое сохранение");
    return true;
}

bool MainWindow::LoadSave()
{
    std::ifstream   fin;
    save            point;

    fin.open("save.dat", std::ios::binary | std::ios::in);
    if (!fin.is_open())
    {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл загрузки");
        return false;
    }

    else
    {
    fin.read((char*)&point, sizeof(save));

    money           = point.money;
    day             = point.day;
    month           = point.month;
    year            = point.year;
    satiety         = point.satiety;
    hunger          = point.hunger;
    mental_condition= point.mental_condition;
    HP              = point.HP;
    damage          = point.damage;
    jobID           = point.jobID;
    tireness        = point.tireness;
    xp              = point.xp;
    chance          =point.chance;
    jobStatus(jobID);
    }

    fin.close();

    QMessageBox::information(this, "Успех", "Сохранение загружено; нажмите 'Играть'");
    startGame();
    return true;
  }

void MainWindow::victory()
{
    timer->stop();

    QMessageBox endingmessage;
    endingmessage.setText("Победа");
    endingmessage.setInformativeText("Поздравляем! Вы успешно окончили университет");
    endingmessage.exec();

    backToTitle();
}

void MainWindow::defeat()
{
    timer->stop();

    QMessageBox endingmessage;
    endingmessage.setText("Поражение");
    endingmessage.setInformativeText("Срок обучения подошёл к концу и Вы не смогли получить диплом");
    endingmessage.exec();

}
