#ifndef CRESERVSYSTEM_H
#define CRESERVSYSTEM_H

#include "model/reserva.h"
#include <list>
#include <QString>
#include <QtSql/QtSql>

class CReservSystem
{
private:
    QSqlDatabase db;
    bool createTables();

public:
    CReservSystem(QString);
    bool createReserva(Reserva r);
    bool deleteReserva(int id);
    std::list<Reserva> readAllReservas();
    std::list<Reserva> searchReservasByDniEspecialidaFecha(QString, QString, QString);
    static QString getDoctor(QString);
};

#endif
