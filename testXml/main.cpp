#include <QCoreApplication>
#include "gestionxml.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    gestionXml xml;
    
    xml.structSenace("C:/Users/Christian GROS/Desktop/xmlClass/test3.xml");
    xml.newSeance("'d'","'d'","'d'","'d'","'d'");
    xml.newSeance("'d'","'d'","'d'","'d'","'d'");
    xml.openFile("C:/Users/Christian GROS/Desktop/xmlClass/test3.xml");
    xml.readElement("dateDepart");

    return a.exec();
}
