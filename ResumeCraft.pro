QT += widgets printsupport
CONFIG += c++17
TEMPLATE = app
TARGET = ResumeCraft

SOURCES += \
    src/PersonalInfo.cpp \
    src/Education.cpp \
    src/Experience.cpp \
    src/Skill.cpp \
    src/UserProfile.cpp \
    src/TemplateEngine.cpp \
    src/PDFExporter.cpp \
    src/mainwindow.cpp \
    main.cpp

HEADERS += \
    include/PersonalInfo.h \
    include/Education.h \
    include/Experience.h \
    include/Skill.h \
    include/UserProfile.h \
    include/TemplateEngine.h \
    include/PDFExporter.h \
    include/MainWindow.h

FORMS += \
    ui/mainwindow.ui

# Ensure app can find templates/assets when run from build dir by setting working dir to project dir (IDE-specific)
QMAKE_DISTCLEAN += *.user

# Copy assets/templates/icons to build directory after link
QMAKE_POST_LINK += $$QMAKE_MKDIR $$DESTDIR/ui $$escape_expand(\n\t)
QMAKE_POST_LINK += $$QMAKE_MKDIR $$DESTDIR/ui/templates $$escape_expand(\n\t)
QMAKE_POST_LINK += $$QMAKE_MKDIR $$DESTDIR/ui/icons $$escape_expand(\n\t)
QMAKE_POST_LINK += $$QMAKE_MKDIR $$DESTDIR/assets $$escape_expand(\n\t)
QMAKE_POST_LINK += $$QMAKE_COPY_DIR $$PWD/ui/templates $$DESTDIR/ui/templates $$escape_expand(\n\t)
QMAKE_POST_LINK += $$QMAKE_COPY_DIR $$PWD/assets $$DESTDIR/assets $$escape_expand(\n\t)
QMAKE_POST_LINK += $$QMAKE_COPY_DIR $$PWD/ui/icons $$DESTDIR/ui/icons
