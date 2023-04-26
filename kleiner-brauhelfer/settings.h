#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QPalette>
#include <QFont>
#ifdef QT_PRINTSUPPORT_LIB
#include <QPrinter>
#endif

class Settings : public QSettings
{
    Q_OBJECT

public:

    enum Theme
    {
        Unused,
        Bright,
        Dark
    };

    enum Module {
        ModuleKein                  = 0x00000000,
        //
        ModuleSudauswahl            = 0x00000001,
        ModuleRezept                = 0x00000002,
        ModuleBraudaten             = 0x00000004,
        ModuleAbfuellen             = 0x00000008,
        ModuleGaerverlauf           = 0x00000010,
        ModuleAusdruck              = 0x00000020,
        ModuleEtikette              = 0x00000040,
        ModuleBewertung             = 0x00000080,
        ModuleBrauuebersicht        = 0x00000100,
        ModuleAusruestung           = 0x00000200,
        ModuleRohstoffe             = 0x00000400,
        _deprecatedModuleDatenbank  = 0x00000800,
        //
        ModuleWasseraufbereitung    = 0x00010000,
        ModulePreiskalkulation      = 0x00020000,
        ModuleLagerverwaltung       = 0x00040000,
        ModuleSpeise                = 0x00080000,
        ModuleSchnellgaerprobe      = 0x00100000,
        //
        ModuleDefault               = ModuleSudauswahl | ModuleRezept | ModuleBraudaten | ModuleAbfuellen |
                                      ModuleGaerverlauf | ModuleAusdruck | ModuleRohstoffe |
                                      ModuleLagerverwaltung | ModuleBrauuebersicht,
        ModuleAlle                  = 0xffffffff,
    };
    Q_DECLARE_FLAGS(Modules, Module)

public:
    explicit Settings(QObject *parent = nullptr);
    Settings(const QString& dir, QObject *parent = nullptr);
    virtual ~Settings();

    void setValueInGroup(const QString &group, const QString &key, const QVariant &value);
    QVariant valueInGroup(const QString &group, const QString &key, const QVariant &defaultValue = QVariant());

    int logLevel();
    void setLogLevel(int level);
    void initLogLevel(int level);

    Theme theme() const;
    void setTheme(Theme theme);

    QString style();
    void setStyle(const QString &style);

    bool useSystemFont();
    void setUseSystemFont(bool system);
    void setFont(const QFont &font);

    bool animationsEnabled();
    void setAnimationsEnabled(bool enabled);

    QString language();
    void setLanguage(QString lang);

    QString settingsDir() const;

    QString databasePath();
    void setDatabasePath(const QString& path);
    QString databaseDir();

    QString dataDir(int type) const;

    void initModules();
    Modules modules() const;
    void enableModule(Module module, bool enabled);
    bool isModuleEnabled(Module module) const;

    QString lastProgramVersion();
    bool isNewProgramVersion();

  #ifdef QT_PRINTSUPPORT_LIB
    QPrinter* createPrinter();
    void savePrinter(const QPrinter* printer);
  #endif

signals:
    void modulesChanged(Settings::Modules modules);

private:
    void initTheme();

public:
    QFont font;

    QPalette palette;
    QPalette paletteInput;
    QPalette paletteError;
    QPalette paletteErrorButton;
    QPalette paletteErrorLabel;
    QPalette paletteChanged;

    QColor ErrorBase;
    QColor ErrorText;

    QColor colorMalz;
    QColor colorHopfen;
    QColor colorHefe;
    QColor colorZusatz;
    QColor colorWasser;
    QColor colorRast;
    QColor colorAnhang;
    QColor colorKommentar;

    QColor NichtGebrautBackground;
    QColor GebrautBackground;
    QColor AbgefuelltBackground;
    QColor VerbrauchtBackground;
    QColor MekrlisteBackground;

    QList<QColor> HopfenTypBackgrounds;
    QList<QColor> HefeTypOgUgBackgrounds;
    QList<QColor> HefeTypTrFlBackgrounds;
    QList<QColor> WZTypBackgrounds;

    QColor DiagramLinie1;
    QColor DiagramLinie2;
    QColor DiagramLinie3;
    QColor DiagramLinie1Light;
    QColor DiagramLinie2Light;
    QColor DiagramLinie3Light;

    // run-time settings
    bool ForceEnabled = false;
    bool modulesFirstTime = false;

private:
    Theme mTheme;
    Modules mModules;
    QFont defaultFont;
    QPalette defaultPalette;
};

#endif // SETTINGS_H
