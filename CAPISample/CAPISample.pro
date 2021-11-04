QT += gui core widgets

CONFIG += c++11 console
CONFIG -= app_bundle


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        polarisv.cpp

HEADERS += \
    mainwindow.h \
    polarisv.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../CAPILibary/release/ -lcapi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../CAPILibary/debug/ -lcapi
else:unix: LIBS += -L$$OUT_PWD/../CAPILibary/ -lcapi

INCLUDEPATH += $$PWD/../CAPILibary
DEPENDPATH += $$PWD/../CAPILibary

FORMS += \
    mainwindow.ui

