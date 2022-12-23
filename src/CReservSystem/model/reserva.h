#ifndef RESERVA_H
#define RESERVA_H

#include <QString>

struct Reserva
{
    QString id_reserva;
    QString dni;
    QString nombre_paciente;
    QString especialidad_reserva;
    QString nombre_doctor;
    QString fecha;
    QString hora;

    Reserva();

    static int n_id_reserva;
    static int n_dni;
    static int n_paciente;
    static int n_especialidad;
    static int n_doctor;
    static int n_fecha;
    static int n_hora;
};

#endif
