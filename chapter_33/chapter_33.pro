TEMPLATE	= app
QT          += widgets
HEADERS         = MyView.h \
    HelpBrowser.h \
    paintscene.h
SOURCES		= main.cpp  \
    paintscene.cpp
RESOURCES       = \
    resource.qrc
windows:TARGET	= ../chapter_33

DISTFILES +=

