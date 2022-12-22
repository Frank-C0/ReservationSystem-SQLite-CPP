#include "ReservationGUI/reservationmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon("./logo_doctor.ico"));

    ReservationMainWindow main_window;
    main_window.show();



    return app.exec();
}
