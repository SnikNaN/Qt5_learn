TEMPLATE     = app
QT          += widgets printsupport
RESOURCES    = resource.qrc
HEADERS      = SyntaxHighlighter.h \
    TextEditor.h
SOURCES	     = SyntaxHighlighter.cpp \
               TextEditor.cpp \
               main.cpp
windows:TARGET = ../chapter_10

