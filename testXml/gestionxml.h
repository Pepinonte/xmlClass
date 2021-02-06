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
    void setElement(QString data);
    void newSenace(QString dateArrivee, QString dateDepart, QString heureDepart, QString heureArrivee, QString type);
private:
    QDomDocument document;
    QFile file;
    QDomNode noeud;
    QDomElement element;
    QDomElement dom_element;

};

#endif // GESTIONXML_H
