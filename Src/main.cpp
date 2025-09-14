#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {

QGuiApplication app(argc, argv);
QQmlApplicationEngine engine;

engine.loadFromModule(u"ReportCreator", u"Main");
return app.exec();
}