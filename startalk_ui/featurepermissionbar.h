/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef FEATUREPERMISSIONBAR_H
#define FEATUREPERMISSIONBAR_H

#include <QWidget>
#include <QUrl>

#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
#include <QtWebEngineWidgets/QWebEnginePage>
#endif
QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
QT_END_NAMESPACE

class FeaturePermissionBar : public QWidget {
Q_OBJECT

public:
    FeaturePermissionBar(QWidget*);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    void requestPermission(const QUrl &, QWebEnginePage::Feature feature);
#endif

signals:
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    void featurePermissionProvided(const QUrl &securityOrigin, QWebEnginePage::Feature, QWebEnginePage::PermissionPolicy);
#endif
private slots:
    void permissionDenied();
    void permissionGranted();
    void permissionUnknown();

	virtual void showEvent(QShowEvent *) override;

private:
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    QWebEnginePage::Feature m_feature;
#endif
    QLabel *m_messageLabel;
    QUrl m_securityOrigin;
	QPushButton *allowButton;
};

#endif // FEATUREPERMISSIONBAR_H