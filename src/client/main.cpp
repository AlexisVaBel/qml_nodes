#include <functional>
#include <iostream>

#include "ui/DumpWidget.h"
#include <docopt/docopt.h>
#include <QApplication>
#include <spdlog/spdlog.h>

static constexpr auto USAGE =
		R"(Naval Fate.

    Usage:
          naval_fate ship new <name>...
          naval_fate ship <name> move <x> <y> [--speed=<kn>]
          naval_fate ship shoot <x> <y>
          naval_fate mine (set|remove) <x> <y> [--moored | --drifting]
          naval_fate (-h | --help)
          naval_fate --version
 Options:
          -h --help     Show this screen.
          --version     Show version.
          --speed=<kn>  Speed in knots [default: 10].
          --moored      Moored (anchored) mine.
          --drifting    Drifting mine.
)";

int main(int argc, char** argv) {
	/*std::map<std::string, docopt::value> args = docopt::docopt(USAGE,
    { std::next(argv), std::next(argv, argc) },
    true,// show help if requested
    "Naval Fate 2.0");// version string

  for (auto const &arg : args) {
    std::cout << arg.first << arg.second << std::endl;
  }
*/
	QApplication app(argc, argv);

	//Use the default logger (stdout, multi-threaded, colored)
	spdlog::info("Hello, {}!", "World");
	client::ui::DumpWidget widget;
	widget.show();

	fmt::print("Hello, from {}\n", "{fmt}");
	return app.exec();

} // namespace ui