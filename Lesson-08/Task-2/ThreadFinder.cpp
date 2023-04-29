#include "ThreadFinder.h"

ThreadFinder::ThreadFinder(const QDir& dir, const QStringList& mask, QObject *parent)
    : QThread (parent)
    , m_dir(dir)
    , m_mask(mask)
    , m_work (true)
{

}

void ThreadFinder::run()
{

    m_result.clear();
    proceed(m_dir);
    emit foundFiles(m_result);
    emit stopedThread();

}

void ThreadFinder::proceed(const QDir& _dir)
{
    if (!m_work)
        return;

    QStringList listFiles =
        _dir.entryList(m_mask, QDir::Files);

    foreach (QString file, listFiles)
    {
        m_result.append(_dir.absoluteFilePath(file));
    }

    QStringList listDir = _dir.entryList(QDir::Dirs);
    foreach (QString subdir, listDir)
    {
        if (subdir == "." || subdir == "..")
        {
            continue;
        }
        proceed(QDir(_dir.absoluteFilePath(subdir)));
    }

}
