#include "ARM360.h"
#include "ARM360Plugin.h"

#include <QtCore/QtPlugin>

ARM360Plugin::ARM360Plugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void ARM360Plugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool ARM360Plugin::isInitialized() const
{
    return initialized;
}

QWidget *ARM360Plugin::createWidget(QWidget *parent)
{
    return new ARM360(parent);
}

QString ARM360Plugin::name() const
{
    return "ARM360";
}

QString ARM360Plugin::group() const
{
    return "My Plugins";
}

QIcon ARM360Plugin::icon() const
{
    return QIcon();
}

QString ARM360Plugin::toolTip() const
{
    return QString();
}

QString ARM360Plugin::whatsThis() const
{
    return QString();
}

bool ARM360Plugin::isContainer() const
{
    return false;
}

QString ARM360Plugin::domXml() const
{
    return "<widget class=\"ARM360\" name=\"ARM360\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>100</width>\n"
        "   <height>100</height>\n"
        "  </rect>\n"
        " </property>\n"
        "</widget>\n";
}

QString ARM360Plugin::includeFile() const
{
    return "ARM360.h";
}
