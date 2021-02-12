#include <QCoreApplication>
#include "gestionxml.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    gestionXml xml;

    xml.openFile("C:/Users/Christian GROS/Desktop/xmlClass/test3.xml");
//    xml.readElement("dateDepart");
//    xml.modElement("dateDepart");
    xml.supElement("seance");
//    xml.newSeance("a","b","c","c","d");
//    xml.newSeance("a","b","c","c","d");
//    xml.newSeance("a","b","c","c","d");

    return a.exec();
}
