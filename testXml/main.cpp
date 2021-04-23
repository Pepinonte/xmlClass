#include <QCoreApplication>
#include "gestionxml.h"
#include "sockettest.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    gestionXml xml;


    SocketTest cTest;
//    cTest.Connect();

    xml.openFile("C:/Users/Christian GROS/Documents/xmlClass/test3.xml");

//    xml.readElement("dateArrivee");
//    xml.structSenace("C:/Users/Christian GROS/Documents/Projet NS2/xmlClass/test3.xml");

//    xml.newSeance("a","b","c","c","d");

//    xml.modElement(xml);

//    xml.supElement("2");

//    xml.setSenace("2");
//    for (int i=0;i<=4;i++)
//    {
//        qDebug()<<xml.getTab(i);
//    }

//    xml.getNumberId();
    qDebug()<<xml.idDay("ven. avr. 23 2021");
    qDebug()<<xml.idDay("a");

//    xml.supElement(xml.idDay("a"));


    return a.exec();
}
