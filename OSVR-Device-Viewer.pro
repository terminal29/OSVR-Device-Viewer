TEMPLATE = app
TARGET = OSVR-Device-Viewer
INCLUDEPATH += .
INCLUDEPATH += GeneratedFiles
QT += gui widgets
LIBS += -losvrClientKit -losvrCommon

HEADERS += global_states.h \
           interface_element.h \
           osvr_controller_viewer.h \
           path_tree_iterator.h \
           qpathviewer.h \
           QRefreshButton.h \
           GeneratedFiles/ui_osvr_controller_viewer.h
FORMS += osvr_controller_viewer.ui
SOURCES += interface_element.cpp \
           main.cpp \
           osvr_controller_viewer.cpp \
           path_tree_iterator.cpp \
           QPathViewer.cpp \
           QRefreshButton.cpp
RESOURCES += osvr_controller_viewer.qrc
