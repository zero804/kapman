/*
 * Copyright 2007-2008 Thomas Gallinari <tg8187@yahoo.fr>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of 
 * the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <KAboutData>

#include <QApplication>
#include <KLocalizedString>
#include <QCommandLineParser>

#include "kapmanmainwindow.h"

int main(int argc, char** argv) {
	// About Kapman
	KAboutData about("kapman", i18n("Kapman"), QLatin1String("1.0.1"),
		i18n("Kapman: Go through the levels escaping ghosts!"),
		KAboutLicense::GPL, i18n("Copyright (c) 2007-2008 The KapTeam"));
	// Alphabetical order of Developers of Kapman
	about.addAuthor(i18n("Alexandre Galinier"), i18n("Developer"), "alex.galinier@gmail.com");
	about.addAuthor(i18n("Nathalie Liesse"), i18n("Developer"), "nathalie.liesse@gmail.com");
	about.addAuthor(i18n("Ömer Fadıl USTA"), i18n("Developer"), "omerusta@gmail.com");
	about.addAuthor(i18n("Pierre-Benoit Besse"), i18n("Developer"), "besse.pb@gmail.com");
	about.addAuthor(i18n("Romain Castan"), i18n("Developer"), "romaincastan@gmail.com");
	about.addAuthor(i18n("Thomas Gallinari"), i18n("Developer"), "tg8187@yahoo.fr");
	about.addCredit(i18n("Roney Gomes"), i18n("Port to KgSound framework"), "roney477@gmail.com");

	// Command line arguments
    QApplication app(argc, argv);
    QCommandLineParser parser;
    KAboutData::setApplicationData(about);
    parser.addVersionOption();
    parser.addHelpOption();
    //PORTING SCRIPT: adapt aboutdata variable if necessary
    about.setupCommandLine(&parser);
    parser.process(app);
    about.processCommandLine(&parser);
	// Create the application
	// Create the main window
	KapmanMainWindow* window = new KapmanMainWindow();
	// Show the main window
	window->show();
	// Execute the application
	return app.exec();
}

