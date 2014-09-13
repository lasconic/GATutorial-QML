TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp ganalytics.cpp

HEADERS += ganalytics.h

RESOURCES += qml.qrc

android {
  ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android_data
  QT += androidextras
  SOURCES += android/androidganalytics.cpp
  HEADERS += android/androidganalytics.h
  OTHER_FILES += \
    android_data/version.xml \
    android_data/res/values/strings.xml \
    android_data/AndroidManifest.xml \
    android_data/src/com/lasconic/QGoogleAnalytics.java
}

ios {
  QMAKE_LFLAGS += -framework SystemConfiguration -framework CoreData -framework AdSupport -ObjC
  LIBS += -L$$PWD/ios/libs -lGoogleAnalyticsServices -lAdIdAccess -lsqlite3.0
  OBJECTIVE_SOURCES += ios/iosanalytics.mm
}

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
