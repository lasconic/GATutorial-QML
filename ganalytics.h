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

#ifndef GANALYTICS_H
#define GANALYTICS_H

#include <QObject>

class PlatformGoogleAnalytics
{
public:
    PlatformGoogleAnalytics() {}
    virtual ~PlatformGoogleAnalytics() {}
    virtual void initTracker() {}
    virtual void sendHit(const QString &screenName) {}
    virtual void sendEvent(const QString &category, const QString &action, const QString &label, long value){}
};

class GoogleAnalytics : public QObject
{
    Q_OBJECT
    PlatformGoogleAnalytics* _pAnalytics;
public:
    explicit GoogleAnalytics(QObject *parent = 0);
    ~GoogleAnalytics();
    void initTracker();
    Q_INVOKABLE void sendHit(const QString &screenName);
    Q_INVOKABLE void sendEvent(const QString &category, const QString &action, const QString &label = "", long value = 0);
};

#endif //GANALYTICS_H
