QT += core widgets 3drender 3dextras

TEMPLATE = lib
CONFIG += c++14
DEFINES += MELFAROBOTS_LIBRARY

SOURCES += \
    controlpanel.cpp \
    robotPosition.cpp\
    rv4flkinematik.cpp \
    rv6slkinematik.cpp \
    robot.cpp \
    mathfunktions.cpp \
    kinematik.cpp \
    robotcontrol.cpp \
    subwindow.cpp

HEADERS += \
    controlpanel.h \
    robotPosition.h\
    rv4flkinematik.h \
    rv6slkinematik.h \
    robot.h \
    mathfunktions.h \
    kinematik.h \
    position.h \
    robotcontrol.h \
    subwindow.h

FORMS += \
    controlpanel.ui \
    robotcontrol.ui


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../widget/release/ -lwidget
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../widget/debug/ -lwidget
#else:unix: LIBS += -L$$OUT_PWD/../widget/ -lwidget

INCLUDEPATH += $$PWD/../widget
DEPENDPATH += $$PWD/../widget
