QT += gui core widgets 3dextras 3dcore

CONFIG += c++11 console
CONFIG -= app_bundle


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        polarispenrv6sl.cpp \
        polaristool.cpp \
        polarisv.cpp

HEADERS += \
    mainwindow.h \
    polarispenrv6sl.h \
    polaristool.h \
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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../3DWidget-main/build/widget/release/ -lwidget
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../3DWidget-main/build/widget/debug/ -lwidget

INCLUDEPATH += $$PWD/../../3DWidget-main/widget
DEPENDPATH += $$PWD/../../3DWidget-main/widget

FORMS += \
    mainwindow.ui


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Robots-main/build/melfaRobots/release/ -lmelfaRobots
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Robots-main/build/melfaRobots/debug/ -lmelfaRobots

INCLUDEPATH += $$PWD/../../Robots-main/melfaRobots
DEPENDPATH += $$PWD/../../Robots-main/melfaRobots
