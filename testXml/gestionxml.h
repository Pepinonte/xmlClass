#ifndef GESTIONXML_H
#define GESTIONXML_H

#include <QCoreApplication>
#include <QtXml>
#include <QDebug>

class gestionXml
{
public:
    gestionXml();
    void openFile(QString path);
    void readElement(QString data);
    void structSenace(QString path);
    void newSeance(QString dateArrivee, QString dateDepart, QString heureDepart, QString heureArrivee, QString type);

private:
    QDomDocument document;
    QFile file;
    QDomNode noeud;
    QDomElement element;
    QDomElement dom_element;
};

#endif // GESTIONXML_H
