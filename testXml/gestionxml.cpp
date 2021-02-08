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
    file.close();
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

    QDomElement docEle = document.documentElement();
    QDomNodeList elements = docEle.elementsByTagName("seances");

    QDomElement seance = document.createElement("seance");
    seance.setAttribute("id", 2);

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

