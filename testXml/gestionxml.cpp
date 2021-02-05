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


QString gestionXml::setElement(QString data)
{
    return("rien,nada");
}
