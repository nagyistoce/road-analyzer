#-------------------------------------------------
#
# Project created by QtCreator 2012-05-16T18:56:44
#
#-------------------------------------------------

QT       += core gui
TARGET = diplom
CONFIG   += console

TEMPLATE = app

SOURCES += main.cpp \
    engine.cpp \
    appdata.cpp \
    appwindow.cpp \
    dataunit.cpp \
    abstrpreprocesseddata.cpp \
    abstrprocesseddata.cpp \
    preprocessedframe.cpp \
    preprocessedvideo.cpp \
    appmanagewidget.cpp \
    filenavwidget.cpp \
    openfilewidget.cpp \
    setconfwidget.cpp \
    doubleframeshowwidget.cpp \
    frameshowwidget.cpp \
    videocontrolwidget.cpp \
    analyzer.cpp \
    processedframe.cpp \
    processedvideo.cpp \
    abstrfiledata.cpp \
    framefiledata.cpp \
    videofiledata.cpp \
    xmlfiledata.cpp \
    guifacadclass.cpp \
    datafacadclass.cpp

HEADERS += \
    engine.h \
    appdata.h \
    appwindow.h \
    dataunit.h \
    abstrpreprocesseddata.h \
    abstrprocesseddata.h \
    preprocessedframe.h \
    preprocessedvideo.h \
    appmanagewidget.h \
    filenavwidget.h \
    openfilewidget.h \
    setconfwidget.h \
    doubleframeshowwidget.h \
    frameshowwidget.h \
    videocontrolwidget.h \
    analyzer.h \
    processedframe.h \
    processedvideo.h \
    dataTypes.h \
    abstrfiledata.h \
    framefiledata.h \
    videofiledata.h \
    xmlfiledata.h \
    guifacadclass.h \
    datafacadclass.h

INCLUDEPATH += F:\DevTools\opencv\build\include\

LIBS += -LF:\DevTools\opencv\build\x86\vc10\lib \
-lopencv_contrib231 \
-lopencv_legacy231 \
-lopencv_ml231 \
-lopencv_haartraining_engine \
-lopencv_video231 \
-lopencv_ts231 \
-lopencv_gpu231 \
-lopencv_objdetect231 \
-lopencv_calib3d231 \
-lopencv_features2d231 \
-lopencv_highgui231 \
-lopencv_flann231 \
-lopencv_imgproc231 \
-lopencv_core231
