QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    book.cpp \
    book_add.cpp \
    book_change.cpp \
    book_filter.cpp \
    book_statics.cpp \
    bookmanager.cpp \
    login.cpp \
    main.cpp \
    signup.cpp \
    welcome.cpp

HEADERS += \
    about.h \
    book.h \
    book_add.h \
    book_change.h \
    book_filter.h \
    book_statics.h \
    bookmanager.h \
    login.h \
    signup.h \
    welcome.h

FORMS += \
    about.ui \
    book_add.ui \
    book_change.ui \
    book_filter.ui \
    book_statics.ui \
    bookmanager.ui \
    login.ui \
    signup.ui \
    welcome.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src/src.qrc
