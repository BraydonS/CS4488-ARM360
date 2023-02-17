QT += testlib widgets
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS +=  *.h \ 
            headers/*.h \
            ../ARM360/headers

SOURCES +=  *.cpp \
            src/*.cpp

INCLUDEPATH += ../ARM360/headers \ 
                ./headers
