QT          += widgets
HEADERS      = Widget.h \
               WidgetDrag.h \
               dropwidget.h
SOURCES      = main.cpp \
               Widget.cpp \
               dropwidget.cpp
               
windows:TARGET = ../chapter_29

DISTFILES +=

RESOURCES += \
    resource.qrc
