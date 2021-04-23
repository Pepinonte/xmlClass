#include <QCoreApplication>
#include "gestionxml.h"
#include "sockettest.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    gestionXml xml;


    SocketTest cTest;
    cTest.Connect();

//    xml.openFile("C:/Users/Christian GROS/Documents/xmlClass/test3.xml");

//    xml.readElement("dateDepart");
//    xml.structSenace("C:/Users/Christian GROS/Documents/Projet NS2/xmlClass/test3.xml");

//    xml.newSeance("a","b","c","c","d");

//    xml.modElement(xml);

//    xml.supElement("2");

//    xml.setSenace("1");
//    for (int i=0;i<=4;i++)
//    {
//        qDebug()<<xml.getTab(i);
//    }

    xml.getNumberId();


    return a.exec();
}
