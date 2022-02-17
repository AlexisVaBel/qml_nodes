#include <QApplication>

#include <client/ui/DumpWidget.h>

#include "spdlog/sinks/stdout_sinks.h"
#include <docopt/docopt.h>
#include <functional>
#include <iostream>
#include <QQmlApplicationEngine>
#include <spdlog/spdlog.h>

static constexpr auto USAGE =
		R"(QML NODES.

    Usage:
          TODO - prepare usage
 Options:
          -h --help     Show this screen.
          --version     Show version.
)";

auto initLog() {
	auto console = spdlog::stdout_logger_mt("console");
	spdlog::set_default_logger(console);
	spdlog::set_pattern("[source %s] [function %!] [line %#] %v");
	return console;
}

int main(int argc, char** argv) {
	SPDLOG_INFO("initiated app");

	QApplication app(argc, argv);

	SPDLOG_INFO("initiated qml engine");

	QQmlApplicationEngine engine;
	const QUrl url(QStringLiteral("qrc:/ui/qml/main.qml"));
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
			&app, [url](QObject *obj, const QUrl &objUrl) {
				if (!obj && url == objUrl)
					QCoreApplication::exit(-1);
			}, Qt::QueuedConnection);
	engine.load(url);

	return app.exec();

} // namespace ui