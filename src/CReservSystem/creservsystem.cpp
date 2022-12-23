#include "creservsystem.h"

#include <QMessageBox>

bool CReservSystem::createTables()
{
    QSqlQuery query1;
    return query1.exec(
        "CREATE TABLE IF NOT EXISTS reserva ("\
            "id_reserva INTEGER PRIMARY KEY AUTOINCREMENT,"\
            "dni VARCHAR (8),"\
            "paciente VARCHAR(20),"\
            "especialidad VARCHAR(20),"\
            "doctor VARCHAR(20),"\
            "fecha VARCHAR(10),"\
            "hora VARCHAR(10)"\
        ");"
        );
}
CReservSystem::CReservSystem(QString file_name)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(file_name);
    if (!db.open())
        QMessageBox::warning(0, "Error", "Couldn't open database file.");

    createTables();
}
QString CReservSystem::getDoctor(QString especialidad)
{
    if (especialidad == "Otorrinolaringología")
        return "Luis G.";
    if (especialidad == "Endocrinología")
        return "Mario Hurtado";
    if (especialidad == "Estomatología")
        return "Nicolasa Ripoll";
    if (especialidad == "Hematología")
        return "Nerea Bernabeu";
    if (especialidad == "Hepatología")
        return "Jaume Duarte";
    if (especialidad == "Neurología")
        return "Anna Barros";
    if (especialidad == "Neurología")
        return "Minerva San-Juan";
    if (especialidad == "Psiquiatría")
        return "Carles Carballo";
    if (especialidad == "Reumatología")
        return "Orlando Ros";
    if (especialidad == "Dermatología")
        return "Inmaculada Gil";
    if (especialidad == "Oftalmología")
        return "Elvira Palomo";
    return "Desconocido";
}
bool CReservSystem::createReserva(Reserva r)
{
    QSqlQuery query2;
    query2.prepare("INSERT INTO reserva (dni, paciente, especialidad, doctor, fecha, hora) "\
                    "VALUES (:dni, :paciente, :especialidad, :doctor, :fecha, :hora);");

    query2.bindValue(":dni", r.dni);
    query2.bindValue(":paciente", r.nombre_paciente);
    query2.bindValue(":especialidad", r.especialidad_reserva);
    query2.bindValue(":doctor", CReservSystem::getDoctor(r.especialidad_reserva));
    query2.bindValue(":fecha", r.fecha);
    query2.bindValue(":hora", r.hora);

    return query2.exec();
}

bool CReservSystem::deleteReserva(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM reserva WHERE id_reserva = (:id_reserva)");
    query.bindValue(":id_reserva", id);

    return query.exec();
}

std::list<Reserva> CReservSystem::readAllReservas()
{
    std::list<Reserva> lista_reservas;
    QSqlQuery query3("SELECT * FROM reserva;");

    while (query3.next())
    {
        Reserva reserva;
        reserva.id_reserva              = query3.value(Reserva::n_id_reserva).toString();
        reserva.dni                     = query3.value(Reserva::n_dni).toString();
        reserva.nombre_paciente         = query3.value(Reserva::n_paciente).toString();
        reserva.especialidad_reserva    = query3.value(Reserva::n_especialidad).toString();
        reserva.nombre_doctor           = query3.value(Reserva::n_doctor).toString();
        reserva.fecha                   = query3.value(Reserva::n_fecha).toString();
        reserva.hora                    = query3.value(Reserva::n_hora).toString();

        lista_reservas.push_back(reserva);
    }
    return lista_reservas;
}
std::list<Reserva> CReservSystem::searchReservasByDniEspecialidaFecha(QString dni, QString especialidad, QString fecha)
{
    QSqlQuery query3("SELECT * FROM reserva WHERE "\
                        "dni LIKE '" + dni + "%' AND "\
                        "especialidad LIKE '" + especialidad + "%' AND "\
                        "fecha LIKE '" + fecha + "%';");

    std::list<Reserva> lista_reservas;
    while (query3.next())
    {
        Reserva reserva;
        reserva.id_reserva              = query3.value(Reserva::n_id_reserva).toString();
        reserva.dni                     = query3.value(Reserva::n_dni).toString();
        reserva.nombre_paciente         = query3.value(Reserva::n_paciente).toString();
        reserva.especialidad_reserva    = query3.value(Reserva::n_especialidad).toString();
        reserva.nombre_doctor           = query3.value(Reserva::n_doctor).toString();
        reserva.fecha                   = query3.value(Reserva::n_fecha).toString();
        reserva.hora                    = query3.value(Reserva::n_hora).toString();

        lista_reservas.push_back(reserva);
    }
    return lista_reservas;
}
