TEMPLATE     = app
QT          += widgets
SOURCES	     = main.cpp \
               GrabWidget.cpp \
               SystemTray.cpp
HEADERS      = GrabWidget.h \
		SystemTray.h
windows:TARGET = ../chapter_35

RESOURCES += \
    images.qrc
