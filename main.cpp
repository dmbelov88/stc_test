#include <QGuiApplication>
#include <QDebug>
#include <QtWidgets>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controller.h"
#include "sqlquerymodel.h"
#include "eximhelper.h"

int main(int argc, char *argv[])
{
    qDebug() << QT_VERSION_STR;
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    qmlRegisterType<ExImOperationType>("ExImOperationType", 1, 0, "ExImOperationType");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    auto *controller = new Controller();
    if (!controller->init())
        return -1;

    QObject::connect(qApp, &QApplication::destroyed, [&controller]{ delete controller; });

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("controller", controller);
    engine.rootContext()->setContextProperty("personTableModel",
                                             controller->getTableModel(Controller::ModelType::Person));
    engine.rootContext()->setContextProperty("clientTableModel",
                                             controller->getTableModel(Controller::ModelType::Connection));

    engine.load(QUrl(QStringLiteral("qrc:/QML/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
