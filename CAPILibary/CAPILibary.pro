QT       -= gui

TARGET = capi
TEMPLATE = lib

DEFINES += CAPI_LIBRARY


SOURCES += \
        MarkerData.cpp \
        GbfButton1D.cpp \
        ToolData.cpp \
        SystemAlert.cpp \
        Transform.cpp \
        CombinedApi.cpp \
        TcpConnection.cpp \
        GbfFrame.cpp \
        BufferedReader.cpp \
        SystemCRC.cpp \
        GbfData6D.cpp \
        GbfSystemAlert.cpp \
        GbfContainer.cpp \
        ComConnection.cpp \
        GbfData3D.cpp \
        GbfComponent.cpp \
        PortHandleInfo.cpp

HEADERS += \
        Transform.h \
        MarkerData.h \
        CombinedApi.h \
        ToolData.h \
        PortHandleInfo.h \
        SystemAlert.h \
        TcpConnection.h \
        ComConnection.h \
        GbfFrame.h \
        GbfButton1D.h \
        GbfData3D.h \
        GbfContainer.h \
        BufferedReader.h \
        GbfData6D.h \
        GbfComponent.h \
        GbfSystemAlert.h \
        Connection.h \
        SystemCRC.h \
