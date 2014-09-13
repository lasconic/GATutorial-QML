//=============================================================================
// Copyright (c) 2014 Nicolas Froment

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//=============================================================================

#include "ganalytics.h"
#include <QDebug>

#ifdef Q_OS_IOS
#include "ios/iosanalytics.h"
#endif

#ifdef Q_OS_ANDROID
#include "android/androidganalytics.h"
#endif

GoogleAnalytics::GoogleAnalytics(QObject *parent)
    : QObject(parent)
{
#ifdef Q_OS_IOS
    _pAnalytics = new IosGoogleAnalytics();
#elif defined(Q_OS_ANDROID)
    _pAnalytics = new AndroidGoogleAnalytics();
#else
    _pAnalytics = new PlatformGoogleAnalytics();
#endif
}

GoogleAnalytics::~GoogleAnalytics()
{
    delete _pAnalytics;
}

void GoogleAnalytics::initTracker()
{
    _pAnalytics->initTracker();
}

void GoogleAnalytics::sendHit(const QString &screenName)
{
    _pAnalytics->sendHit(screenName);
}

void GoogleAnalytics::sendEvent(const QString &category, const QString &action, const QString &label, long value)
{
    qDebug() << value;
    _pAnalytics->sendEvent(category, action, label, value);
}
