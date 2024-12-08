QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Bayan.h \
    Cymbals.h \
    Drums.h \
    Guitar.h \
    Instrument.h \
    Percussion.h \
    Piano.h \
    Stringed.h \
    Trumpet.h \
    Violin.h \
    Wind.h \
    conUserWin.h \
    encryption.h \
    mainwindow.h \
    user.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    MusiChoose_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

CONFIG += link_pkgconfig
PKGCONFIG += openssl

LIBS += -L"C:/libs/openssl/lib" -lssl -lcrypto
INCLUDEPATH += "C:/libs/openssl/include"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    bayan.txt \
    cymbals.txt \
    drums.txt \
    guitar.txt \
    logo_style.css \
    piano.txt \
    references.txt \
    trumpet.txt \
    users.txt \
    violin.txt
