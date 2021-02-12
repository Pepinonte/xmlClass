#include "gestionxml.h"
#include <iostream>

gestionXml::gestionXml()
{

}

void gestionXml::openFile(QString path)
{
    file.setFileName(path);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<< "erreur lors de l'ouverture";
    else
    {
        if(!document.setContent(&file))
            qDebug()<< "erreur lors du chargement";
    }
//    file.close();
}

void gestionXml::readElement(QString data)
{
    dom_element = document.documentElement();

    noeud = dom_element.firstChild();

    QDomElement domElement = noeud.toElement();
        while (!noeud.isNull()) {
            QDomElement domElement = noeud.toElement();
            if (!domElement.isNull()) {
                if (domElement.tagName() == "seance") {
                    QDomNode node = domElement.firstChild();
                    while (!node.isNull()) {
                        QDomElement element = node.toElement();
                        if (!element.isNull()) {
                            const QString tagName(element.tagName());
                            if (tagName == data) {
                                qDebug() << data << " is:" << element.text();
                            }
                        node = node.nextSibling();
                        }
                    }
                }
            }
                noeud = noeud.nextSibling();
    }
    file.close();
}

void gestionXml::structSenace(QString path)
{
    QString fileXmlName = path;
    QFile fileXml(fileXmlName);

    // Ouverture du fichier en écriture et en texte. (sort de la fonction si le fichier ne s'ouvre pas)
    if(!fileXml.open(QFile::WriteOnly | QFile::Text))
        qDebug()<<"erreur";

    QXmlStreamWriter writer(&fileXml);

    // Active l'indentation automatique du fichier XML pour une meilleur visibilité
    writer.setAutoFormatting(true);

    // Insert la norme de codification du fichier XML
    writer.writeStartDocument();

    // Élément racine du fichier XML
    writer.writeStartElement("seances");

    // Finalise le document XML
    writer.writeEndDocument();

    // Fermer le fichier pour bien enregistrer le document et ferme l'élément root
    fileXml.close();

}

void gestionXml::newSeance(QString dateArrivee, QString dateDepart, QString heureDepart, QString heureArrivee, QString type)
{

    QFile file("C:/Users/Christian GROS/Desktop/xmlClass/test3.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    }
    QDomDocument document;
    if (!document.setContent(&file))
    {
        qDebug() << "failed to parse file";
        file.close();
    }

    file.close();



    QDomNodeList umgVars = dom_element.elementsByTagName("seance");

    QDomNode lastElem = umgVars.at(umgVars.size() - 1);
    dom_element = document.documentElement();
    noeud = dom_element.firstChild();
    QDomElement domElement = noeud.toElement();
    QDomElement lastEEEE = lastElem.toElement();
    int id = 0;

    while (!noeud.isNull()) {
        QDomElement domElement = noeud.toElement();
        if (!domElement.isNull()) {
            id++;
            qDebug()<<id;
            if (domElement.attribute("id")!="") {
                id++;
                qDebug()<<id;
                qDebug()<<domElement.attribute("id").toInt();
                id = domElement.attribute("id").toInt();
            }
            qDebug()<<"nop";
        }
        noeud = noeud.nextSibling();
    }
    file.close();


    QDomElement docEle = document.documentElement();
    QDomNodeList elements = docEle.elementsByTagName("seances");

    QDomElement seance = document.createElement("seance");
    seance.setAttribute("id", id+1);

    QDomElement dateArEle = document.createElement("dateArrivee");
    QDomText dateArCont = document.createTextNode(dateArrivee);

    QDomElement dateDeEle = document.createElement("dateDepart");
    QDomText dateDeCont = document.createTextNode(dateDepart);

    QDomElement heureArEle = document.createElement("heureArrivee");
    QDomText heureArCont = document.createTextNode(heureArrivee);

    QDomElement heureDeEle = document.createElement("heureDepart");
    QDomText heureDeCont = document.createTextNode(heureDepart);

    QDomElement typeEle = document.createElement("typeClient");
    QDomText typeCont = document.createTextNode(type);

    dateArEle.appendChild(dateArCont);
    dateDeEle.appendChild(dateDeCont);
    heureArEle.appendChild(heureArCont);
    heureDeEle.appendChild(heureDeCont);
    typeEle.appendChild(typeCont);

    seance.appendChild(dateArEle);
    seance.appendChild(heureArEle);
    seance.appendChild(dateDeEle);
    seance.appendChild(heureDeEle);
    seance.appendChild(typeEle);

    docEle.appendChild(seance);

    QFile outFile( "C:/Users/Christian GROS/Desktop/xmlClass/test3.xml" );

    if( !outFile.open( QIODevice::WriteOnly | QIODevice::Text ) )
        qDebug( "Failed to open file for writing." );

    QTextStream stream( &outFile );
    stream << document.toString();

    outFile.close();

}

void gestionXml::modElement(QString data)
{


    QFile file("C:/Users/Christian GROS/Desktop/xmlClass/test3.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    }
    QDomDocument document;
    if (!document.setContent(&file))
    {
        qDebug() << "failed to parse file";
        file.close();
    }

    file.close();




    dom_element = document.documentElement();

    noeud = dom_element.firstChild();

    QDomElement domElement = noeud.toElement();
        while (!noeud.isNull()) {
            QDomElement domElement = noeud.toElement();
            if (!domElement.isNull()) {
                if (domElement.tagName() == "seance") {
                    QDomNode node = domElement.firstChild();
                    while (!node.isNull()) {
                        QDomElement element = node.toElement();
                        if (!element.isNull()) {
                            const QString tagName(element.tagName());
                            if (tagName == data) {
                                qDebug() << data << " is:" << element.text();
                                QDomElement dateArEle = document.createElement("dateArrivee");
                                QDomText dateArCont = document.createTextNode("eeeeee");


                                QDomNodeList umgVars = dom_element.elementsByTagName("dateArrivee");
                                if(!umgVars.isEmpty())
                                {
                                    QDomNode lastElem = umgVars.at(umgVars.size() - 1);
                                    lastElem.parentNode().removeChild(lastElem);
                                }



                                element.appendChild(dateArCont);
                            }
                        node = node.nextSibling();
                        }
                    }
                }
            }
                noeud = noeud.nextSibling();
    }
    file.close();










    QFile outFile( "C:/Users/Christian GROS/Desktop/xmlClass/test3.xml" );

    if( !outFile.open( QIODevice::WriteOnly | QIODevice::Text ) )
        qDebug( "Failed to open file for writing." );

    QTextStream stream( &outFile );
    stream << document.toString();

    outFile.close();


}

void gestionXml::supElement(QString data)
{

    QFile file("C:/Users/Christian GROS/Desktop/xmlClass/test3.xml");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    }
    QDomDocument document;
    if (!document.setContent(&file))
    {
        qDebug() << "failed to parse file";
        file.close();
    }

    file.close();

    dom_element = document.documentElement();
    QDomNodeList umgVars = dom_element.elementsByTagName("seance");

//    if(!umgVars.isEmpty())
//    {
//        QDomNode lastElem = umgVars.at(umgVars.size() - 1);
//        lastElem.parentNode().removeChild(lastElem);
//    }
    ////////////////////////////////////////////////////////////////:
//    QDomNode lastElem = umgVars.at(umgVars.size() - 1);
//    noeud = dom_element.firstChild();
//    QDomElement domElement = noeud.toElement();
//    QDomElement lastEEEE = lastElem.toElement();
//    int id = 0;

//    while (!noeud.isNull()) {
//        QDomElement domElement = noeud.toElement();
//        if (!domElement.isNull()) {
//            id++;
//            qDebug()<<id;
//            if (domElement.attribute("id")!="2") {
//                qDebug()<<"ok";
//                lastElem.parentNode().removeChild(domElement.firstChild());
//            }
//            qDebug()<<"nop";
//        }
//        noeud = noeud.nextSibling();
//    }
//    file.close();


    int id = 0;
    QDomNode lastElem = umgVars.at(umgVars.size() - 1);
    dom_element = document.documentElement();
    noeud = dom_element.firstChild();
    QDomElement domElement = noeud.toElement();
    QDomElement lastEEEE = lastElem.toElement();

    while (!noeud.isNull()) {
        QDomElement domElement = noeud.toElement();
        if (!domElement.isNull()) {
            if (domElement.tagName()=="seance" && domElement.attribute("id")=="2") {
                qDebug()<<domElement.attribute("id").toInt();
//                domElement.removeChild(domElement.firstChildElement());
                qDebug()<<domElement.nodeValue().toInt();
                id = domElement.attribute("id").toInt();
                lastElem.parentNode().removeChild(lastElem);
            }
            qDebug()<<"nop";
        }
        noeud = noeud.nextSibling();
    }
    file.close();


















    QFile outFile( "C:/Users/Christian GROS/Desktop/xmlClass/test3.xml" );

    if( !outFile.open( QIODevice::WriteOnly | QIODevice::Text ) )
        qDebug( "Failed to open file for writing." );

    QTextStream stream( &outFile );
    stream << document.toString();

    outFile.close();
}
