#include <QCoreApplication>
#include "gestionxml.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDomDocument document;
    gestionXml xml;

    xml.openFile("C:/Users/Christian GROS/Desktop/xmlClass/test3.xml");
    xml.getElement("typeClient");
    xml.setElement("rien");
    xml.newSenace("1", "2", "3", "4", "5");

    return a.exec();
}
