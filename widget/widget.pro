QT +=  core widgets 3drender 3dextras printsupport

TEMPLATE = lib
DEFINES += WIDGET_LIBRARY

QMAKE_CXXFLAGS += -fopenmp
QMAKE_LFLAGS += -fopenmp

CONFIG += c++14

SOURCES += \
    cameracontroller.cpp\
    coordinatesystem.cpp \
    kinectcamera.cpp \
    linearaxis.cpp \
    liveplot.cpp \
    liveplot2.cpp \
    qcustomplot.cpp \
    rv4fl.cpp \
    rv6sl.cpp \
    sixjointrobot.cpp \
    stlmesh.cpp \
    widget3d.cpp \
    pointcloud.cpp \
    point.cpp

HEADERS += \
    coordinatesystem.h \
    kinectcamera.h \
    liveplot.h \
    liveplot2.h \
    qcustomplot.h \
    rv4fl.h \
    rv6sl.h \
    sixjointrobot.h \
    stlmesh.h \
    tool.h \
    widget3d.h \
    cameracontroller.h \
    pointcloud.h \
    point.h \
    linearaxisrv6sl.h \
    linearaxis.h

LIBS += -fopenmp

FORMS += \
    liveplot.ui \
    liveplot2.ui
