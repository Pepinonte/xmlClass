#include "gestionxml.h"
#include <iostream>

gestionXml::gestionXml()
{

}

void gestionXml::openFile(QString chemin)
{
    file.setFileName(chemin);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<< "erreur lors de l'ouverture";
    }
    else
    {
        if(!document.setContent(&file))
        {
            qDebug()<< "erreur lors du chargement";
        }
        file.close();
    }
}


void gestionXml::getElement(QString data)
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


void gestionXml::setElement(QString data)
{
    QDomElement docElem = document.documentElement();

    QDomElement write_elem = document.createElement("information");
    write_elem.setAttribute("id", 2);
    docElem.appendChild(write_elem);

    if(!file.open(QIODevice::WriteOnly))
    {
        file.close();
        qDebug()<<"Erreur","Impossible d'écrire dans le document XML";
    }

    QString write_doc = document.toString();
    QTextStream stream(&file);
    stream << write_doc;
    file.close();


}


void gestionXml::newSenace(QString dateArrivee, QString dateDepart, QString heureDepart, QString heureArrivee, QString type)
{
    QString fileXmlName = "C:/Users/Christian GROS/Desktop/xmlClass/test3.xml";
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

    // Ajoute l'élément "seance" dans le fichier XML
    writer.writeStartElement("seance");

    // Ajoute un élément "dateArrivee", lui applique le texte "bzhenel" et ferme l'élément "nom"
    writer.writeTextElement("dateArrivee", dateArrivee);

    // Ajoute l'élément "heureArrivee", lui applique le texte "www.bzhenel.fr" et ferme l'élément "url"
    writer.writeTextElement("heureArrivee", heureArrivee);

    // Ajoute un élément "dateArrivee", lui applique le texte "bzhenel" et ferme l'élément "nom"
    writer.writeTextElement("dateDepart", dateDepart);

    // Ajoute l'élément "heureArrivee", lui applique le texte "www.bzhenel.fr" et ferme l'élément "url"
    writer.writeTextElement("heureDepart", heureDepart);

    // Ajoute l'élément "heureArrivee", lui applique le texte "www.bzhenel.fr" et ferme l'élément "url"
    writer.writeTextElement("typeClient", type);

    // Ferme l'élément seance
    writer.writeEndElement();

    // Finalise le document XML
    writer.writeEndDocument();

    // Fermer le fichier pour bien enregistrer le document et ferme l'élément root
    fileXml.close();
}
