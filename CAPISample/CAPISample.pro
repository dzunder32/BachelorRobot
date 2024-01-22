QT += gui core widgets 3dextras 3dcore

CONFIG += c++11 console
CONFIG -= app_bundle


SOURCES += \
        drawletters.cpp \
        main.cpp \
        mainwindow.cpp \
        polaristool.cpp \
        polarisv.cpp

HEADERS += \
    drawletters.h \
    mainwindow.h \
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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../widget/release/ -lwidget
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../widget/debug/ -lwidget

INCLUDEPATH += $$PWD/../widget
DEPENDPATH += $$PWD/../widget

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../melfaRobots/release/ -lmelfaRobots
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../melfaRobots/debug/ -lmelfaRobots

INCLUDEPATH += $$PWD/../melfaRobots
DEPENDPATH += $$PWD/../melfaRobots

FORMS += \
    drawletters.ui \
    mainwindow.ui


