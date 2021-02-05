#include <QCoreApplication>
#include "gestionxml.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDomDocument document;
    gestionXml gestX;

    gestX.openFile("C:/Users/Christian GROS/Desktop/testXml/test3.xml");
    gestX.getElement("typeClient");

    return a.exec();
}
