#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dateprocessor.cpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game_over       (false),
    money           (1200),
    day             (1),
    month           (9),
    year            (2021),
    satiety         (100.f),
    hunger          (0.5f),
    mental_condition(100.f),
    tireness        (0.5f),
    HP              (100.f),
    damage          (0.f),
    jobID           (0),
    xp              (0),
    chance          (0)
{
    ui->setupUi(this);

    //Главное меню
    QObject::connect(ui->button_quit,   &QPushButton::clicked, this, &MainWindow::quit);
    QObject::connect(ui->button_play,   &QPushButton::clicked, this, &MainWindow::startGame);
    QObject::connect(ui->Save,          &QPushButton::clicked, this, &MainWindow::Save);
    QObject::connect(ui->LoadSave,      &QPushButton::clicked, this, &MainWindow::LoadSave);

    //Игровая панель
    QObject::connect(ui->button_back_title,     &QPushButton::clicked, this, &MainWindow::backToTitle);
    QObject::connect(ui->button_stats,          &QPushButton::clicked, this, &MainWindow::toStats);
    QObject::connect(ui->button_jobs,           &QPushButton::clicked, this, &MainWindow::toJobs);
    QObject::connect(ui->button_shop,           &QPushButton::clicked, this, &MainWindow::toShop);
    QObject::connect(ui->button_leisure,        &QPushButton::clicked, this, &MainWindow::toLeisure);
    QObject::connect(ui->button_educ,           &QPushButton::clicked, this, &MainWindow::toEduc);

    //Магазин
    QObject::connect(ui->button_shop_option1,   &QPushButton::clicked, this, &MainWindow::shopOption1);
    QObject::connect(ui->button_shop_option2,   &QPushButton::clicked, this, &MainWindow::shopOption2);
    QObject::connect(ui->button_shop_option3,   &QPushButton::clicked, this, &MainWindow::shopOption3);
    QObject::connect(ui->button_shop_option4,   &QPushButton::clicked, this, &MainWindow::shopOption4);
    QObject::connect(ui->button_shop_option5,   &QPushButton::clicked, this, &MainWindow::shopOption5);
    QObject::connect(ui->button_shop_option6,   &QPushButton::clicked, this, &MainWindow::shopOption6);
    QObject::connect(ui->button_shop_option7,   &QPushButton::clicked, this, &MainWindow::shopOption7);
    QObject::connect(ui->button_shop_option8,   &QPushButton::clicked, this, &MainWindow::shopOption8);
    QObject::connect(ui->button_shop_option9,   &QPushButton::clicked, this, &MainWindow::shopOption9);
    QObject::connect(ui->button_shop_option10,  &QPushButton::clicked, this, &MainWindow::shopOption10);
    QObject::connect(ui->button_shop_option11,  &QPushButton::clicked, this, &MainWindow::shopOption11);
    QObject::connect(ui->button_shop_option12,  &QPushButton::clicked, this, &MainWindow::shopOption12);
    QObject::connect(ui->button_shop_option13,  &QPushButton::clicked, this, &MainWindow::shopOption13);
    QObject::connect(ui->button_shop_option14,  &QPushButton::clicked, this, &MainWindow::shopOption14);
    QObject::connect(ui->button_shop_option15,  &QPushButton::clicked, this, &MainWindow::shopOption15);

    //Работа
    jobStatus(jobID); //установка статуса безработного в начале игры
    QObject::connect(ui->button_jobs_option1,   &QPushButton::clicked, this, &MainWindow::jobsOption1);
    QObject::connect(ui->button_jobs_option2,   &QPushButton::clicked, this, &MainWindow::jobsOption2);
    QObject::connect(ui->button_jobs_option3,   &QPushButton::clicked, this, &MainWindow::jobsOption3);
    QObject::connect(ui->button_jobs_option4,   &QPushButton::clicked, this, &MainWindow::jobsOption4);
    QObject::connect(ui->button_jobs_option5,   &QPushButton::clicked, this, &MainWindow::jobsOption5);
    QObject::connect(ui->button_jobs_option6,   &QPushButton::clicked, this, &MainWindow::jobsOption6);

    // Досуг
    QObject::connect(ui->button_leisure_option1,   &QPushButton::clicked, this, &MainWindow::LeisureOption1);
    QObject::connect(ui->button_leisure_option2,   &QPushButton::clicked, this, &MainWindow::LeisureOption2);
    QObject::connect(ui->button_leisure_option3,   &QPushButton::clicked, this, &MainWindow::LeisureOption3);
    QObject::connect(ui->button_leisure_option4,   &QPushButton::clicked, this, &MainWindow::LeisureOption4);
    QObject::connect(ui->button_leisure_option5,   &QPushButton::clicked, this, &MainWindow::LeisureOption5);
    QObject::connect(ui->button_leisure_option6,   &QPushButton::clicked, this, &MainWindow::LeisureOption6);
    QObject::connect(ui->button_leisure_option7,   &QPushButton::clicked, this, &MainWindow::LeisureOption7);
    QObject::connect(ui->button_leisure_option8,   &QPushButton::clicked, this, &MainWindow::LeisureOption8);
    QObject::connect(ui->button_leisure_option9,   &QPushButton::clicked, this, &MainWindow::LeisureOption9);
    QObject::connect(ui->button_leisure_option10,   &QPushButton::clicked, this, &MainWindow::LeisureOption10);
    QObject::connect(ui->button_leisure_option11,   &QPushButton::clicked, this, &MainWindow::LeisureOption11);
    QObject::connect(ui->button_leisure_option12,   &QPushButton::clicked, this, &MainWindow::LeisureOption12);
    QObject::connect(ui->button_leisure_option13,   &QPushButton::clicked, this, &MainWindow::LeisureOption13);

    //образование
    QObject::connect(ui->button_educ1,   &QPushButton::clicked, this, &MainWindow::EducOption1);
    QObject::connect(ui->button_educ2,   &QPushButton::clicked, this, &MainWindow::EducOption2);
    QObject::connect(ui->button_educ3,   &QPushButton::clicked, this, &MainWindow::EducOption3);
    QObject::connect(ui->button_educ4,   &QPushButton::clicked, this, &MainWindow::EducOption4);
    QObject::connect(ui->button_educ5,   &QPushButton::clicked, this, &MainWindow::EducOption5);
    QObject::connect(ui->button_educ6,   &QPushButton::clicked, this, &MainWindow::EducOption6);
    QObject::connect(ui->button_session,   &QPushButton::clicked, this, &MainWindow::EducOption7);
    QObject::connect(ui->button_session2,   &QPushButton::clicked, this, &MainWindow::EducOption8);
    QObject::connect(ui->button_courseWork,   &QPushButton::clicked, this, &MainWindow::EducOption9);
    QObject::connect(ui->button_courseWork2,   &QPushButton::clicked, this, &MainWindow::EducOption10);
    QObject::connect(ui->button_GraduateWork,   &QPushButton::clicked, this, &MainWindow::EducOption11);
    QObject::connect(ui->button_GraduateWork2,   &QPushButton::clicked, this, &MainWindow::EducOption12);

    //настройка внешнего вида интерфейса
    setFixedSize                                        (1000, 600);

    ui->stack->setCurrentIndex                          (0);
    setWindowTitle                                      ("Главное меню");

    ui->frame_game_buttons->            hide();         //скрыть кнопки игровой панели изначально
    ui->label_shop_greeting->           setStyleSheet   ("font-size: 30px"); //заголовок в магазине
    ui->label_jobs_greeting->           setStyleSheet   ("font-size: 30px"); //заголовок в работе
    ui->label_stats_greeting->          setStyleSheet   ("font-size: 30px"); //заголовок в характеристиках
    ui->label_name->                    setStyleSheet   ("font-size: 50px"); //заголовок в главном меню
    ui->button_play->                   setFixedHeight  (50); //ширина кнопок регулируется параметрами layoutLeft(Right)margin, поэтому устанавливаю только высоту
    ui->button_quit->                   setFixedHeight  (50);
    ui->Save->                          setFixedHeight  (50);
    ui->LoadSave->                      setFixedHeight  (50);
    ui->progressBar_hunger->            setFormat       ("Сытость: " + QString::number(satiety) + ", затрата на день: " + QString::number(hunger));
    ui->progressBar_mental_condition->  setFormat       ("Настроение: " + QString::number(mental_condition) + ", затрата на день: " + QString::number(tireness));
    ui->progressBar_health->            setFormat       ("Здоровье: " + QString::number(HP)+ ", потери в день: " + QString::number(damage)); // здоровье может тратится в день в случае отравления или увеличиваться, когда ты ляжешь в больницу на пару дней, например, но по умолчание затраты =0
    ui->label_xp->                      setText         ("Опыт: " + QString::number(xp));

    //немного графики
    ui->frame_game_buttons->            setStyleSheet   ("border: 1px solid"); //контур

    //всплывающие уведомления
    hunger_death =                      new             QMessageBox();
    hunger_death->                      setText         ("Вы погибли от голода");
    hunger_death->                      setModal        (true);
    mental_condition_death =            new             QMessageBox();
    mental_condition_death->            setText         ("Вы погибли от психического расстройства");
    mental_condition_death->            setModal        (true);
    HP_death =                          new             QMessageBox();
    HP_death->                          setText         ("Вы умерли");
    hunger_death->                      setModal        (true);
    shop_notEnoughMoney =               new             QMessageBox();
    shop_notEnoughMoney->               setModal        (true);
    leisure_notEnoughMoney =            new             QMessageBox();
    leisure_notEnoughMoney->            setModal        (true);
    Start_Game =                        new             QMessageBox();
    Start_Game->                        setText         ("Добро пожаловать в симмулятор студента, достигнете максимальных высот за ваши 4 года обучения");
    FinalGame =                         new             QMessageBox();
    FinalGame->                         setText         ("Поздравляем вы закончили учебу в университете");

}
MainWindow::~MainWindow()
{
    delete ui;
    delete hunger_death;
    delete shop_notEnoughMoney;
}

