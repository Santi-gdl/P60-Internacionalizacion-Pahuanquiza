#include "principal.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator T;
    QStringList langs;
    langs<<"Espanol"<<"Italiano"<<"Koreano";
    const QString lang = QInputDialog::getItem(NULL,
                                               "Language",
                                               "Select a Language",
                                               langs);

    if (lang == "Italiano"){
        T.load(":/MiPaint_it.qm");
    }else if (lang == "Koreano"){
        T.load(":/MiPaint_ko.qm");
    }
    if (lang !="Espanol"){
        a.installTranslator(&T);
    }
    Principal w;
    w.show();
    return a.exec();
}
