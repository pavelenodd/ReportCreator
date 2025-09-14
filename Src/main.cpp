#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "read_doc.h"

int main(int argc, char *argv[]) {

QGuiApplication app(argc, argv);
QQmlApplicationEngine engine;

engine.loadFromModule(u"ReportCreator", u"Main");
return app.exec();
}