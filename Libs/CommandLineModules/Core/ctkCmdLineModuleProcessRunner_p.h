/*=============================================================================
  
  Library: CTK
  
  Copyright (c) German Cancer Research Center,
    Division of Medical and Biological Informatics
    
  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at
  
    http://www.apache.org/licenses/LICENSE-2.0
    
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
  
=============================================================================*/

#ifndef CTKCMDLINEMODULEPROCESSRUNNER_P_H
#define CTKCMDLINEMODULEPROCESSRUNNER_P_H

#include <QObject>
#include <QProcess>

#include "ctkCmdLineModuleProcessFuture.h"

class ctkCmdLineModuleProcessRunner : public QObject, public QRunnable, public ctkCmdLineModuleProcessFutureInterface
{
  Q_OBJECT

public:

  ctkCmdLineModuleProcessRunner(const QString& location, const QStringList& args);

  ctkCmdLineModuleProcessFuture start();

  void run();

protected Q_SLOTS:

  void processStarted();

  void processFinished(int exitCode, QProcess::ExitStatus status);

  void processError(QProcess::ProcessError);

private:

  QProcess process;
  const QString location;
  const QStringList args;
};

#endif // CTKCMDLINEMODULEPROCESSRUNNER_P_H