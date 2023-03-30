TEMPLATE	= app
QT          += widgets
HEADERS         = MyView.h \
    HelpBrowser.h \
    mainwindow.h \
    paintscene.h
SOURCES		= main.cpp  \
    mainwindow.cpp \
    paintscene.cpp
RESOURCES       = \
    resource.qrc
windows:TARGET	= ../chapter_34

DISTFILES +=

