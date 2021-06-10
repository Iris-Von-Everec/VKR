QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += PRO_FILE_PWD=$$sprintf("\"\\\"%1\\\"\"", $$_PRO_FILE_PWD_)

SOURCES += \
    data.cpp \
    file.cpp \
    file_search.cpp \
    filesystem.cpp \
    main.cpp \
    manager.cpp \
    parser.cpp \
    tag.cpp

HEADERS += \
    data.h \
    file.h \
    file_search.h \
    filesystem.h \
    manager.h \
    parser.h \
    tag.h

FORMS += \
    manager.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
