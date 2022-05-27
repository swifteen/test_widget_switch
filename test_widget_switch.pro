QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QMAKE_CXXFLAGS += -g -Og

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
				funcbar.cpp \
				main.cpp \
				base_dialog.cpp \
                                datetime_dialog.cpp \
				patient_dialog.cpp \
				base_main_dialog.cpp \
				sample_dialog.cpp \
				statusbar.cpp \
				preview_dialog.cpp \
				file_manager_dialog.cpp \
				setting_dialog.cpp

HEADERS += \
				funcbar.h \
				statusbar.h \
				base_dialog.h \
                                datetime_dialog.h \
				patient_dialog.h \        
				main_dialog_def.h \
				base_main_dialog.h\
				sample_dialog.h \
				preview_dialog.h \
				file_manager_dialog.h \
				setting_dialog.h

FORMS += \
				funcbar.ui \
				statusbar.ui \
				patient_dialog.ui \
                                datetime_dialog.ui \
				sample_dialog.ui \
				preview_dialog.ui \
				file_manager_dialog.ui \
				setting_dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
