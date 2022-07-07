#ifndef SAVES_H
#define SAVES_H

struct save {       //структура для сейва, в слоте есть объяснение зачем
    unsigned long long  money;
    int                 day,
                        month,
                        year;

    float               satiety, hunger;
    float               mental_condition, tireness;
    float               HP;
    float               damage;
    int                 jobID;
    int                 xp;
    int                 chance;
};

#endif // SAVES_H
