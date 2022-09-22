TEMPLATE = subdirs
SUBDIRS += \
    src/gui \
    src/abalonecore \
    src/tui \
    tests

src-tui.depends = src/abalonecore
tests.depends = src/abalonecore

OTHER_FILES += \
    config.pri \
    Doxyfile \
    ../../README.md \
    ../../.gitignore
