#ifndef GESTIONXML_H
#define GESTIONXML_H

#include <QCoreApplication>
#include <QtXml>
#include <QDebug>

class gestionXml
{
public:
    gestionXml();
    void getElement(QString data);
    void openFile(QString chemin);
    QString setElement(QString data);

private:
    QDomDocument document;
    QFile file;
    QDomNode noeud;
    QDomElement element;
    QDomElement dom_element;

};

#endif // GESTIONXML_H
