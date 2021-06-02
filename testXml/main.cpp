#include <QCoreApplication>
#include "gestionxml.h"
#include "sockettest.h"
#include <iostream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    gestionXml xml;
    SocketTest cTest;

    xml.openFile("C:/Users/Christian GROS/Documents/xmlClass/test3.xml");

//    qDebug()<<xml.idDay("ven. avr. 23 2021");
//    qDebug()<<xml.idDay("a");

    int choix;

    std::cout<<"fait ton choix";
    std::cin>>choix;

    switch (choix) {
        case 0: xml.newSeance("a","b","c","c","d");

        case 1: xml.modElement(xml);

//        case 3: xml.supElement(xml.idDay("a"));


        case 3: xml.readElement("dateArrivee");

        case 4: xml.structSenace("C:/Users/Christian GROS/Documents/Projet NS2/xmlClass/test3.xml");

        case 5: xml.getNumberId();

//        case 6:
//            int id = xml.getNumberId();
//            QString str;
//            xml.setSenace(str.setNum(id));

        case 7:
            for (int i=0;i<=4;i++)
            {
                QString tab = xml.getTab(i);
                qDebug()<<tab.toUtf8();
            }

        case 8:
            xml.setSenace("30");
            for (int i=0;i<=4;i++)
            {
                qDebug()<<xml.getTab(i);
            }

        case 9: cTest.Connect();

        default:
            std::cout<<"erreur";
    }

    return a.exec();
}
