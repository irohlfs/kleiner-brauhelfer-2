# kleiner-brauhelfer v2
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/kleiner-brauhelfer/kleiner-brauhelfer-2)](https://github.com/kleiner-brauhelfer/kleiner-brauhelfer-2/releases/latest/)
[![GitHub Release Date](https://img.shields.io/github/release-date/kleiner-brauhelfer/kleiner-brauhelfer-2)](https://github.com/kleiner-brauhelfer/kleiner-brauhelfer-2/releases/latest/)
[![GitHub Downlaods](https://img.shields.io/github/downloads/kleiner-brauhelfer/kleiner-brauhelfer-2/total)](https://github.com/kleiner-brauhelfer/kleiner-brauhelfer-2/releases/latest/)

Der kleine-brauhelfer ist ein Hilfsprogramm für Hobbybrauer zum Erstellen und Verwalten von Biersuden. Die Version 2 ist die Weiterentwicklung vom [kleinen-brauhelfer](http://github.com/Gremmel/kleiner-brauhelfer).

- <img src="kleiner-brauhelfer/images/de.svg" width="16"> verfügbar auf Deutsch
- <img src="kleiner-brauhelfer/images/en.svg" width="16"> available in English
- <img src="kleiner-brauhelfer/images/se.svg" width="16"> finns på svenska
- <img src="kleiner-brauhelfer/images/nl.svg" width="16"> beschikbaar in het nederlands

<img src="doc/sudauswahl.png" width="240"><img src="doc/rezept.png" width="240"><img src="doc/braudaten.png" width="240"><img src="doc/abfuelldaten.png" width="240"><img src="doc/gaerverlauf.png" width="240"><img src="doc/spickzettel.png" width="240"><img src="doc/zusammenfassung.png" width="240"><img src="doc/etikett.png" width="240"><img src="doc/bewertung.png" width="240"><img src="doc/brauuebersicht.png" width="240"><img src="doc/ausruestung.png" width="240"><img src="doc/rohstoffe.png" width="240">

**Diskussionsthread:**

https://hobbybrauer.de/forum/viewtopic.php?f=3&t=21510

**Credits:**
- Bibliothek für Diagramme: [QCustomPlot](http://www.qcustomplot.com)
- Code für Mustache Templates: [Qt Mustache](http://github.com/robertknight/qt-mustache)
- Code HTML Syntaxhighlighting: [Evgenii Legotckoi](http://evileg.com/en/post/218/)
- Flaggenicons: [Freepik](http://www.flaticon.com/authors/freepik) von [www.flaticon.com](http://www.flaticon.com/)


## Download
- [Download](https://github.com/kleiner-brauhelfer/kleiner-brauhelfer-2/releases/latest/)
- [Changelog](CHANGELOG.md)

### Windows
- **kbh2_v2.x.x_setup_win_x64.exe**: Installationsdatei für 64bit System
- **kbh2_v2.x.x_portable_win_x64.zip**: Portable Version für 64bit System

### Linux
- **kbh2_v2.x.x_linux_x64.deb**: Debian Packet für 64bit System
  - Benötigt zusätzlich:
    - [Qt 6](https://www.qt.io/download-qt-installer) inklusiv WebEngine Modul
    - OpenSSL 1.1.1b oder höher
- **kleiner-brauhelfer-2-x86_64.AppImage**: Portable Version (AppImage) für 64bit System
  
### Mac OS
- **kbh2_v2.x.x_macos.zip**: Installationsdatei für Mac OS

## Hinweise

### Skalierung anpassen
Standardmässig wird der kleine-brauhelfer automatisch anhand der Pixeldichte des Monitors skaliert. Ist dies nicht erwünscht, kann diese Option mit dem Startparameter *QT_AUTO_SCREEN_SCALE_FACTOR=0* deaktiviert werden. Zusätzlich kann mit dem Startparameter *QT_SCALE_FACTOR=1.5* einen beliebigen Skalierungsfaktor angegeben werden (hier 150%).

### Qt Installation unter Linux
Alternativ zum offiziellen Qt Installer (https://www.qt.io/download-qt-installer) kann Qt mit [Another Qt installer(aqt)](https://github.com/miurahr/aqtinstall) installiert werden:
```
# Configure
VERSION='5.15.2'
QT_PATH="/opt/Qt"

# Location for logs and download files
mkdir /tmp/aqt
cd /tmp/aqt

# Install helper (https://github.com/miurahr/aqtinstall)
sudo pip install aqtinstall

# Install Qt
sudo python3 -m aqt install --outputdir ${QT_PATH} ${VERSION} linux desktop -m qtwebengine

# Set ENV variables
export PATH=${QT_PATH}/${VERSION}/clang_64/bin/:$PATH
export QT_PLUGIN_PATH=${QT_PATH}/${VERSION}/clang_64/plugins/
export QML_IMPORT_PATH=${QT_PATH}/${VERSION}/clang_64/qml/
export QML2_IMPORT_PATH=${QT_PATH}/${VERSION}/clang_64/qml/
```
